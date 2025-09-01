const express = require('express');

const app = express();// server created

app.get('/home',(req,res)=>{
  res.end("Welcome to Home Page"); 
})

app.get('/about',(req,res)=>{
  res.end("Welcome to About Page");
})

app.listen(4000,()=>{
  console.log("server is running on port 3000")
})