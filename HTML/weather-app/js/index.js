/*var colorPalette = [
  "red":    "#FF5C5C",
  "orange": "#FFA55C",
  "yellow": "#FFF55C",
  "green":  "#93FF5C",
  "blue":   "#5CFFFF"
];*/

$.getJSON('https://freegeoip.net/json/') 
     .done (function(location){
  $('#country').html(location.country_name);
  $('#city').html(location.city);
  $.getJSON('http://api.openweathermap.org/data/2.5/weather?lat=' + location.latitude + '&lon=' + location.longitude + '&appid=e31c7037ec5cb1859bd16b5f0c93514c', function(output) {

  $('#temp').html(Math.floor(output.main.temp-273) + ' &deg C');    $('#main').html(output.weather[0].main);    $('#desc').html(output.weather[0].description);
 /*$('#icon').attr('src', 'http://openweathermap.org/img/w/' + output.weather[0].icon + '.png');*/
  if(output.weather[0].icon === "01d"){
    $('#icon').attr('src', 'http://image.flaticon.com/icons/svg/53/53565.svg');
  }else if(output.weather[0].icon === "01n"){
    $('#icon').attr('src', 'http://image.flaticon.com/icons/svg/53/53381.svg');
  }
})
     });