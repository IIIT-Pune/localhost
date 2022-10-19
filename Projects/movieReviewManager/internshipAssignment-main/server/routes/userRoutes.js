const express = require ("express") ;
const { registerUser, loginUser, logout, forgotPassword, resetPassword, getUserDetails, updatePassword, updateProfile, getAllUsers, getSingleUsers, getSingleUser, updateUser, deleteUser } = require("../controllers/userController");
const { isAuthenticatedUser } = require("../middleware/auth");

const router = express.Router();

router.route("/register").post(registerUser);
router.route("/login").post(loginUser);
router.route("/password/forgot").post(forgotPassword);
router.route("/password/reset/:token").put(resetPassword);
router.route("/me").get( isAuthenticatedUser ,getUserDetails);
router.route("/password/update").put(isAuthenticatedUser , updatePassword);
router.route("/me/update").put(isAuthenticatedUser , updateProfile);
router.route("/logout").get(logout);



module.exports =router