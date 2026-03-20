import express from "express";
const app = express();

app.get("/", function(req,  res){
    res.send("<h1>MubeelDev</h1>")
})

app.get("/contact",function(req, res){
    res.send("contact me at 'mubeeldev@gmail.com'");
})

app.get("/about",function(req, res){
    res.send("my name is mohammed im a fullstack developer undergrow pray for me mama!")
})


app.listen(3000,function(){
    console.log("server is running on porth 300!");
});
