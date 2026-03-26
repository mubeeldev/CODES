const bodyParser = require("body-parser");
const express = require("express");
const fs = require('fs');
const { title } = require("process");


const app = express();
app.set("view engine","ejs");
app.use(bodyParser.urlencoded({extended:true}));
app.use(express.urlencoded({extended:true}));

app.use(express.json());

const filePath = __dirname + "/data/list.json";

const pageText = {
    title :"TODO LIST APP"
}

// fs helping function for reading file
const readData = () => {
    let data = fs.readFileSync(filePath);
    return JSON.parse(data);
}

// fs helping function for writing file
const writeData =(data) => {
    fs.writeFileSync(filePath,JSON.stringify(data,null,2))
}

let todoitems = readData();

app.get('/',(req,res)=>{
    res.render("index",{todoitems:todoitems.todolist,title:pageText.title});
});

app.post("/",(req,res) => {
    let newItem = {
        id: Date.now(),
        ...req.body
    }

    todoitems.todolist.push(newItem);
    writeData(todoitems);
    res.redirect("/");

});

app.put("/",(req,res)=>{

})


const PORT = 3000;
app.listen(PORT,()=>{
    console.log("......................................");
});





