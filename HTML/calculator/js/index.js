var numbers = [];

$('#seven').on('click', function(numbers){
  //numbers.push(7);
  console.log("test");
});

$('#eight').on('click', function(numbers){
  numbers.push(8);
});

$('#equal').on('click', function(numbers){
  var total = 0;
  for(i = 0; i < numbers.length; i++){
    total = total + numbers(i);
  }
  console.log(total);
});

function addNumbers(first,second){
  return first + second;
}

function subtractNumbers(first,second){
  return first - second;
}

function multiplyNumbers(first,second){
  return first * second;
}

function divideNumbers(first,second){
  return first / second;
}