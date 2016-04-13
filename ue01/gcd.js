function extendedGCD(a, b){

  var c = a
  var d = b
  var uc = 1
  var vc = 0
  var ud = 0
  var vd = 1
  var count = 0

  if (a >= 0 && b >= 0 && ( a != 0 || b != 0)) {
    while (c != 0) {
      var q = Math.floor(d/c)
      var cc = c
      c = d-q*c
      d = cc

      uc = ud-q*uc
      vc = vd-q*vc
      ud = uc
      vd = vc
      count++
    }
    console.log("GCD: "+d+"\n"+ud+" "+vd);
    console.log(count);
  }
}

//get the greatest common divisor
var a = process.argv[2]
var b = process.argv[3]
// extendedGCD(a,b)



var startTime = process.hrtime()
var start = startTime[0] * 1000000 + startTime[1] / 1000
extendedGCD(a,b)
var endTime = process.hrtime()
var end = endTime[0] * 1000000 + endTime[1] / 1000
var time = end - start
console.log(time)
