const express = require("express");
const bodyParser = require("body-parser");
const { render } = require("ejs");

const app = express();
// app.use(bodyParser)
app.set('view engine','ejs');

app.get("/", (req,res)=>{

    const d = new Date();
    const day = d.getDay();
    let current_day;
    let status;

    switch(day){
        case 0:
            current_day = "Sunday";
            status = "It's Week End Take a rest and Be ready for Monday";
        break;
        case 1:
            current_day = "Monday";
            status = "Is a Workiing Day You Have To Work !!!";
        break;
        case 2:
            current_day = "Tuesday";
            status = "Is a Workiing Day You Have To Work !!!";
        break;
        case 3:
            current_day = "Wednesday";
            status = "Is a Workiing Day You Have To Work !!!";
        break;
        case 4:
            current_day = "Thursday";
            status = "Is a Workiing Day You Have To Work !!!";
        break;
        case 5:
            current_day = "Friday";
            status = "Is a Workiing Day You Have To Work !!!";
        break;
        case 6:
            current_day = "Saturday";
            status = "It's Week End Take a rest !!";
        break;
        default:
            console.log("erro")

    };

    res.sendFile(__dirname + "/index.html");
    res.render("list", {day:current_day});
    // res,render('list',{Status: status})
});

app.listen(3000,function(req, res){
    console.log("the server is runinig on porth 3000! ")
})