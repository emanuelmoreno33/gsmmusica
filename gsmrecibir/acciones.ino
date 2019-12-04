void acciones(int actual)
{
  //apagar
  if (actual == 10)
  {
    bocina.disable();
    cancionactual = 1;
    activado = false;
  }
  //prender
  else if(actual == 11)
  {
    canciones(cancionactual);
    activado=true;
  }
  //play
  else if(actual == 14)
  {
    canciones(cancionactual);
    activado=true;
  }
  //pausa
  else if(actual == 15)
  {
    bocina.pause();
  }
  //stop
  else if(actual == 16)
  {
    bocina.disable();
  }
  //adelante
  else if(actual == 13)
  {
   canciones(cancionactual);
   activado = true;
  }
  //atras
  else if(actual == 12)
  {
    canciones(cancionactual);
    activado = true;
  }
  
}
