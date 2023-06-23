class FooGelRender
{
    constructor()
    {
         var pos = new Vec2(10.0, 5.0);
         var mousePos = new Vec2(100.0 ,14.0);
         var dif =   mousePos - pos;

          Log.getInstance().log(INFO,  "GelRender call GelEngine (pos-mousePos) = "+ dif.toString()+Log.endl());
    }

  rotate( angle)
  {
        var rot = new Mat22(angle);
        return rot;
  }
}