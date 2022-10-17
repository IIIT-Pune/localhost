// SPDX-License-Identifier: UNLICENSED

pragma solidity ^0.8.13;

import "./IERC20.sol";

import "https://github.com/OpenZeppelin/openzeppelin-contracts/blob/v4.0.0/contracts/token/ERC20/ERC20.sol";
interface IERC20 {
    function totalSupply() external view returns (uint);

    function balanceOf(address account) external view returns (uint);

    function transfer(address recipient, uint amount) external returns (bool);

    function allowance(address owner, address spender) external view returns (uint);

    function approve(address spender, uint amount) external returns (bool);

    function transferFrom(
        address sender,
        address recipient,
        uint amount
    ) external returns (bool);

    event Transfer(address indexed from, address indexed to, uint value);
    event Approval(address indexed owner, address indexed spender, uint value);
};


  contract Block is IERC20{
    string public name="Block";
    string public symbol="BLK";

    string public decimal ="0";

    uint public override totalSupply;
    address public founder;
    mapping(address=>uint) public balances;
    mapping(address=>mapping(address=>uint)) allowed;

    constructor(){

        totalSupply=10000;
        founder=msg.sender;
        balances[founder]=totalSupply;
    }

    function balanceof(address tokenOwner) public view  returns(uint balance){

        return balances[tokenOwner];
    }

    function transfer(address to,uint tokens)public  override returns(bool success){
        require(balances[msg.sender]>=tokens);
        balances[to]+=tokens;
        balances[msg.sender]-=tokens;
        emit Transfer(msg.sender,to,tokens);
        return true;
    }

    function approve(address spender,uint tokens) public override returns(bool success){

        require(balances[msg.sender]>=tokens);
        require(tokens>0);

        allowed[msg.sender][spender]=tokens;
        emit Approval(msg.sender,spender,tokens);
        return true;
    }

    function allowance(address tokenOwner,address spender) public view override returns(uint numberofTokens){

        return allowed[tokenOwner][spender];
    }

    function transferFrom(address from ,address to,uint tokens) public override returns(bool success){
        require(allowed[from][to]>=tokens);
        require(balances[from]>=tokens);
        balances[from]-=tokens;
        balances[to]+=tokens;
    }
}