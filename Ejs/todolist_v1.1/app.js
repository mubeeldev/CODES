const express = require('express');
const bodyParser = require("body-parser");


const app = express();
const PORT = 3000;

app.set("view engine","ejs");
app.use(bodyParser.urlencoded({extended:true}));

let items = ['eat food','read english'];

app.get("/",(req,res)=>{
    let option = {
        weekday: 'long',
        year :'numeric',
        month : 'long',
        day : 'numeric'
    };
const today = new Date();
const day = today.toLocaleDateString("en-US",option)

    res.render("index",{day , items:items});
});
app.post("/", (req,res) =>{
    let item = req.body.newtodo;
    items.push(item);
    res.redirect("/"); //redirecting the requast to get
})

app.listen(PORT,()=>{
    console.log("server is running on port: "+PORT);
})