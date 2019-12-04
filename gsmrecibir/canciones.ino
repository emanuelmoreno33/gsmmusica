void canciones(int cancion)
{
  bocina.setVolume(5);
  switch(cancion)
  {
    case 1:
    bocina.play("prueba.wav");
    break;
    case 2:
    bocina.play("Happier.wav");
    break;
    case 3:
    bocina.play("lovesong.wav");
    break;
    case 4:
    bocina.play("Instant.wav");
    break;
    case 5:
    bocina.play("10years.wav");
    break;
    case 6:
    bocina.play("babyyours.wav");
    break;
    case 7:
    bocina.play("runaway.wav");
    break;
    case 8:
    bocina.play("slavefear.wav");
    break;
    case 9:
    bocina.play("canggu.wav");
    break;
    case 10:
    bocina.play("eltrsite.wav");
    break;
    case 11:
    bocina.play("prueba.wav");
    break;
//    case 12:
//    bocina.play("enjoysilence.wav");
//    break;
//    case 13:
//    bocina.play("epiphany.wav");
//    break;
//    case 14:
//    bocina.play("everybody.wav");
//    break;
//    case 15:
//    bocina.play("heartbreak.wav");
//    break;
//    case 16:
//    bocina.play("imperialmarch.wav");
//    break;
//    case 17:
//    bocina.play("johnwick.wav");
//    break;
//    case 18:
//    bocina.play("keepmoving.wav");
//    break;
//    case 19:
//    bocina.play("midnightcity.wav");
//    break;
//    case 20:
//    bocina.play("mondayjam.wav");
//    break;
//    case 21:
//    bocina.play("musicaligera.wav");
//    break;
//    case 22:
//    bocina.play("o.wav");
//    break;
//    case 23:
//    bocina.play("opendoor.wav");
//    break;
//    case 24:
//    bocina.play("photograph.wav");
//    break;
//    case 25:
//    bocina.play("runaway.wav");
//    break;

    default:
    bocina.play("prueba.wav");
    break;
  }
}
