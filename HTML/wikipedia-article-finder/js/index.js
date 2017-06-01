$('#button').click(function(){
  getData();
});

function getData() {
  $('.old').remove();
  var searchTerm = $('input:text').val();
  var url = 'https://en.wikipedia.org/w/api.php?action=opensearch&search='+ searchTerm +'&format=json&callback=?';
  $.getJSON(url, function(data){
    for(i = 0; i < 10; i++){
      if(data[1][i] === undefined){
        //Do nothing
      }else{
        $('form').append("<h2 class='old'>" + "<a href='" + data[3][i] + "' target='_blank' class='old'>" + data[1][i] + "</a></h2>");
        $('form').append("<p id='article' class='old'>" + data[2][i] + "</p><hr class='old'>");
      }
    }
  });  
}