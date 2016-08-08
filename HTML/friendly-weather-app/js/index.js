var weekDay = [
  "Sunday",
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursday",
  "Friday",
  "Saturday"
]

$(document).ready(function() {
  $.getJSON('http://ip-api.com/json/').done(function(location) {
    $('#country').html(location.country);
    $('#city').html(location.city);
    $.getJSON('http://api.openweathermap.org/data/2.5/weather?lat=' + location.lat + '&lon=' + location.lon + '&appid=e31c7037ec5cb1859bd16b5f0c93514c', function(output) {
      $('#main').html(output.weather[0].main);    
      $('#desc').html(output.weather[0].description);

      var cTemp = Math.round(output.main.temp-273);
      var fTemp = Math.round((output.main.temp-273)*(9/5) + 32);
 
      $('#temp').html('<span>' + cTemp + ' &degC</span><span style="display:none">' + fTemp + ' &degF</span>');
      $('#temp').click(function(){
      $('span', this).toggle();
      });     
      
      var date = new Date();
      $('#date').html('today is ' + weekDay[date.getDay()]);
      
      /*
        Displaying weather icon based on weather condition
        Icons courtesy of http://www.flaticon.com/packs/justicons
      */
      if(output.weather[0].icon === "01d"){
        $('#icon').attr('src', 'http://image.flaticon.com/icons/svg/53/53565.svg');
      }else if(output.weather[0].icon === "01n"){
        $('#icon').attr('src', 'http://image.flaticon.com/icons/svg/53/53381.svg');
      }else if(output.weather[0].icon === "02d" || output.weather[0].icon === "03d" || output.weather[0].icon === "04d"){
        $('#icon').attr('src', 'http://image.flaticon.com/icons/svg/53/53562.svg');
      }else if(output.weather[0].icon === "02n" || output.weather[0].icon === "03n" || output.weather[0].icon === "04n"){
        $('#icon').attr('src', 'http://image.flaticon.com/icons/svg/53/53385.svg');
      }else if(output.weather[0].icon === "09d" || output.weather[0].icon === "10d"){
        $('#icon').attr('src', 'http://image.flaticon.com/icons/svg/53/53658.svg');
      }else if(output.weather[0].icon === "09n" || output.weather[0].icon === "10n"){
        $('#icon').attr('src', 'http://image.flaticon.com/icons/svg/53/53748.svg');
      }else if(output.weather[0].icon === "11d"){
        $('#icon').attr('src', 'http://image.flaticon.com/icons/svg/53/53577.svg');
      }else if(output.weather[0].icon === "11n"){
        $('#icon').attr('src', 'http://image.flaticon.com/icons/svg/53/53744.svg');
      }else if(output.weather[0].icon === "13d"){
        $('#icon').attr('src', 'http://image.flaticon.com/icons/svg/53/53581.svg');
      }else if(output.weather[0].icon === "13n"){
        $('#icon').attr('src', 'http://image.flaticon.com/icons/svg/53/53558.svg');
      }else if(output.weather[0].icon === "50d"){
        $('#icon').attr('src', 'http://image.flaticon.com/icons/svg/53/53690.svg');
      }else if(output.weather[0].icon === "50n"){
        $('#icon').attr('src', 'http://image.flaticon.com/icons/svg/53/53471.svg');
      }
    })
  });
});