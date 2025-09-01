const http = require('http'); 
const server = http.createServer()  // server created and stored
server.listen(5000,()=>{  // server start
  console.log("server is running on port 5000");
})