const Movie = require("../models/moviesModel") ;
const History = require("../models/historyModel.js");
const User = require("../models/userModels")
const ErrorHandler = require("../utils/errorHandler");
const catchAsyncErrors = require ("../middleware/catchAsyncErros.js") ;
const ApiFeatures = require ("../utils/apifeatures");
const ReviewHistory = require( "../utils/reviewHistory")


exports.createMovie = catchAsyncErrors (async (req ,res , next)=>{
    const { name , description , genre} = req.body ;
    const user = req.user.id;
    const movie = {
        name :name,
        description : description,
        genre:genre,
        user :user
    }
    const movieCreated = await Movie.create(movie);
    res.status(200).json({
        success : true ,
        movie : movieCreated
    })

})

// Getting all Movies 
exports.getAllMovies = catchAsyncErrors( async (req , res) =>{
    const resultPerPage = 5;
    const MovieCount = await Movie.countDocuments();


    //used for searching specific queries
    const apiFeature    =   new ApiFeatures (Movie.find() , req.query)
    .search()
    .filter()
    .pagination(resultPerPage);

    const Movies = await apiFeature.query
    res.status(200).json({
        message : "route is ok" ,
        MovieCount ,
        Movies})

})

// Getting a single Movie 
exports.getMovieDetails = catchAsyncErrors( async (req , res , next) =>{

    let Movie = await Movie.findById(req.params.id);

    if (!Movie) {
        return  next(new ErrorHandler("Movie not found" , 404));
    } else {
        res.status(200).json({
            success : true ,
            
            Movie
        })
            

    }

})





// Create review 

exports.createMovieReview = catchAsyncErrors( async (req , res , next) =>{

    const { rating , comment , MovieId } = req.body ;

    const review = {
        user : req.user._id ,
        name : req.user.name ,
        rating : Number(rating) ,
        comment : comment ,


    } ;
    

    const movie = await Movie.findById(MovieId);
    let addedReviewToHistory;
    let reviewToBeAddedInHistory ;
    
    if (movie) {
        reviewToBeAddedInHistory = {

            movieId : MovieId,
            user : req.user._id ,
            name : req.user.name ,
            rating : Number(rating) ,
            comment : comment ,
            
    
        }
        addedReviewToHistory = await History.create(reviewToBeAddedInHistory);

    } else {
        return next ( new ErrorHandler("invalid movie Id, movie not found" , 404));
    }


    const isReviewed = movie.reviews.find(rev=>rev.user.toString()===req.user._id.toString());
    let message = ""
    if (isReviewed) {
        movie.reviews.forEach(rev =>{
            if(rev.user.toString()===req.user._id.toString()) {
                rev.rating=rating ,
                rev.comment=comment
            }
        })
        message = "review updated successfully"
        
    } else {
        movie.reviews.push(review);
        
        message = "review added successfully"
    }
    Movie.numOfReviews = movie.reviews.length;

    let avgerageRating = 0 ;

    movie.reviews.forEach(rev =>{
        avgerageRating+=rev.rating
    })

    movie.ratings = Number (avgerageRating/movie.reviews.length);

     await movie.save({validateBeforeSave : false});

     res.status(200).json({
         success : true ,
         message : message,
         systemMessage : addedReviewToHistory,
     })
        
})

// Get all reviews 

exports.getAllReviewsForSingleMovie = catchAsyncErrors ( async (req ,res , next)=>{

    const movie = await Movie.findById(req.query.id) ;
    if (!movie) {
        return  next(new ErrorHandler("Movie not found" , 404));
    }

    const reviewsForTheSearchedUtility = movie.reviews ;

    res.status(200).json({
        success : true ,
        message : `here are all the reviews for the tool id: ${movie._id} ` ,
        reviewsForTheSearchedUtility
    })
})


exports.getTheEntireHistoryOfReviewsIntheSystem = catchAsyncErrors(async (req , res , next)=>{
    const reviewHistory = new ReviewHistory (History.find() , req.query).search();

    const searchedReviewHistory = await reviewHistory.query;
    
    res.status(200).json({
        message : "Here is the complete history" ,
        history :searchedReviewHistory
    })
})