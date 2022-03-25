var express = require('express')
var app=express()
var bodyParser = require('body-parser')

app.listen(3000,function(){
	console.log("start! express server on port 3000");
});

app.use(express.static('public'))
app.use(bodyParser.json())
app.use(bodyParser.urlencoded({extended:true}))
app.set('view engine', 'ejs')

 app.get('/', function(req,res){
	 //res.send("<h1>hi frined</h1>")
	 console.log('test');
	 res.sendFile(__dirname + "/public/main.html")
 })