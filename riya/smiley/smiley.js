$(document).ready(function(){
  let eye1=$('#eye1');
  var flag=true;
  eye1.on('click',function(){
    if(flag)
    {
      $(this).css({'border':'-1px solid black','background-color':'black','border-radius': '50%'});
      flag=false;
    }
    else {
      $(this).css({'border-botton':'5px solid black','border-radius': '50px','background-color':'transparent'});
      flag=true;
    }

  })
  let eye2=$('#eye2');
  var flag2=true;
  eye2.on('click',function(){
    if(flag2)
    {
      $(this).css({'border':'-1px solid black','background-color':'black','border-radius': '50%'});
      flag2=false;
    }
    else {
      $(this).css({'border-botton':'5px solid black','border-radius': '50px','background-color':'transparent'});
      flag2=true;
    }

  })

});
