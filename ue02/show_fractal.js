#!/usr/bin/env node
// fractal

var http = require('http'),
    fs = require('fs'),
    open = require('open'),
    port = 8000

    http.createServer(function(request, response) {

        var url = request.url === '/' ? '/index.html' : request.url
        url = '.' + url

        fs.readFile(url, function (err, data) {
          if (err) {
            response.writeHeader(404, {"Content-Type": "application/javascript"})
            response.write(err.toString())
            return response.end()
          }

          response.writeHeader(200, {"Content-Type": "text/html"})
          response.write(data)
          response.end()
        })

    }).listen(port, function(){
      open('http://localhost:8000', 'Google Chrome')
      console.log("Server listening on: http://localhost:%s", port)
    })
