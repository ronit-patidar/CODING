const express = require('express');
const app = express();// server create 
// server program
app.get('/home',(req,res)=>{
  res.send("home page changed");
})
app.get('/about',(req,res)=>{
  res.send("Welcome to about page");
})
// server start
app.listen(5000,()=>{
  console.log("server is running on port 5000")
})
