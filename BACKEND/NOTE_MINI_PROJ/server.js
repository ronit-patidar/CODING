const express = require('express');
// server create  
const app = express();
// server start
// api // tittle and description
app.use(express.json());
// m middleware to parse json data
let notes = [];
app.post("/notes",(req,res)=>{
  console.log(req.body);
  notes.push(req.body);
  res.json({
    message:"Note added successfully",
    notes:notes
  })
})
app.listen(6000,()=>{
  console.log("server is running on port 6000");
})
