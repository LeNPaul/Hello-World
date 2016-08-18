$(document).ready(function(){
  updatePage(accounts);
});

var accounts = ["brunofin","RocketBeansTV","ESL_CSGO","syndicate","riotgames","ESL_SC2", "OgamingSC2", "comster404", "cretetion", "freecodecamp", "storbeck", "habathcx", "RobotCaleb", "noobs2ninjas", "sodapoppin", "Ice_Poseidon"];

function updatePage(accounts) {
  for(i = 0; i < accounts.length;i++){
    getStatus(accounts[i]);
  }  
};

function getStatus(account) {
  var url = 'https://api.twitch.tv/kraken/streams/' + account + '?callback=?'; 
  $.getJSON(url, function(data) {
    if(data.stream === null) {
      $('#offline').append('<div class="block col-md-3"><a href="https://www.twitch.tv/' + account + '" target="_blank"><h4 class="title">' + account + '</h4><img src="https://s-media-cache-ak0.pinimg.com/736x/24/99/03/249903173ee16b3346ba320a24e56a8b.jpg"><h6>User Offline</h6></a></div>');
    }else if(data.stream != null){
      $('#online').append('<div class="block col-md-3"><a href="https://www.twitch.tv/' + account + '" target="_blank"><h4 class="title">' + account + '</h4><img src="' + data.stream.channel.logo + '"><h6>' + data.stream.game + '</h6></a></div>');
    }else{
      $('#notFound').append('<div class="block-offline col-md-3"><h4 class="title">' + account + '</h4><img src="https://s-media-cache-ak0.pinimg.com/736x/24/99/03/249903173ee16b3346ba320a24e56a8b.jpg"><h6>User Does Not Exist</h6></div>');
    }
});  
}