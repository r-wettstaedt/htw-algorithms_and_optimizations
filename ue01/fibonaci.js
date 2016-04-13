// import
var bigInt = require("big-integer")
var startTime

function fibonaciRec(callNum, maxCallNum, old, current) {
  if(callNum.greaterOrEquals(maxCallNum)) {
    var endTime = getCurrentTimeInMicros()
    return {
      fibonaci: current.toString(),
      time: endTime.minus(startTime).toString(),
      iterations: maxCallNum.toString()
    }
  }
  var newOld = current
  var newCurrent = old.plus(current)
  return fibonaciRec(callNum.plus(1), maxCallNum, newOld, newCurrent)
}

function fibonaci(maxCallNum) {
  // cpu time
  startTime = getCurrentTimeInMicros()
  console.log(fibonaciRec(bigInt.zero,maxCallNum, bigInt.zero, bigInt.one))
}

var getCurrentTimeInMicros = function() {
  return bigInt(process.hrtime()[0] * 1000000).plus(bigInt(process.hrtime()[1]).divide(1000))
}

var maxCallNum = bigInt(process.argv[2])
fibonaci(maxCallNum)
