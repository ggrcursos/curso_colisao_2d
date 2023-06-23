class Vec2 {
  constructor(/*float*/ x, /*float*/ y) {
    this.x = x;
    this.y = x;
  }

  /*void*/ Set(/*float*/ x_, /*float*/ y_) {
    this.x = x_;
    this.y = y_;
  }

  /*Vec2*/ opMinus() {
    return new Vec2(-x, -y);
  }

  /*void*/ opPlusEqual(/*Vec2 &*/ v) {
    this.x += v.x;
    this.y += v.y;
  }

  /*void*/ opMinusEqualV(/*Vec2 &*/ v) {
    this.x -= v.x;
    this.y -= v.y;
  }

  /*void*/ opMultEqualS(/*float*/ a) {
    this.x *= a;
    this.y *= a;
  }

  /*float*/ length() {
    return Math.sqrt(this.x * this.x + this.y * this.y);
  }

  /*string*/ toString() {
    return x + "," + y;
  }
}

class Mat22 {
  constructor(/*float*/ angle, /*Vec2 &*/ _col1, /*Vec2 &*/ _col2) {
    this.col1 = new Vec2(0, 0);
    this.col2 = new Vec2(0, 0);

    if (angle) {
      /*float*/ var c = cosf(angle),
        s = sinf(angle);
      col1.x = c;
      col2.x = -s;
      col1.y = s;
      col2.y = c;
      return;
    }
    if (this.col1 && this.col2) {
      this.col1 = col1;
      this.col2 = col2;
    }
  }

  /*Mat22*/ transpose() {
    return Mat22(new Vec2(col1.x, col2.x), new Vec2(col1.y, col2.y));
  }

  /*Mat22*/ Invert() {
    /*float*/ var a = col1.x,
      b = col2.x,
      c = col1.y,
      d = col2.y;
    var B = new Mat22();
    /*float*/ det = a * d - b * c;

    if (det == 0.0) {
      throw new Error("Determinant cannot be zero!");
    }
    det = 1.0 / det;
    B.col1.x = det * d;
    B.col2.x = -det * b;
    B.col1.y = -det * c;
    B.col2.y = det * a;
    return B;
  }
}

/*float*/ function DotVV(a, b)
{
  return a.x * b.x + a.y * b.y;
}

/*float*/ function CrossVV(/*Vec2 */ a, /*Vec2 */ b){
  return a.x * b.y - a.y * b.x;
}

/*Vec2*/ function CrossVS(/*Vec2 &*/ a, /*float*/ s)
{
  return new Vec2(s * a.y, -s * a.x);
}

/*Vec2*/ function CrossSV(/*float*/ s, /*Vec2 &*/ a)
{
  return new Vec2(-s * a.y, s * a.x);
}

/*Vec2*/ function opMutiMV(A, /*Vec2 &*/ v)
{
  return new Vec2(A.col1.x * v.x + A.col2.x * v.y, A.col1.y * v.x + A.col2.y * v.y);
}

/*Vec2*/ function opPlusVV(/*Vec2 &*/ a, /*Vec2 &*/ b)
{
  return new Vec2(a.x + b.x, a.y + b.y);
}

/*Vec2*/ function opMinusVV(/*Vec2 &*/ a, /*Vec2 &*/ b)
{
  return new Vec2(a.x - b.x, a.y - b.y);
}

/*Vec2*/ function opMultSV(/*float*/ s, /*Vec2 &*/ v)
{
  return new Vec2(s * v.x, s * v.y);
}

/*Vec2*/ function opPlusMM(  A,  B)
{
  return Mat22(A.col1 + B.col1, A.col2 + B.col2);
}

/*Vec2*/function  opMultMM(  A,   B)
{
  return new Mat22(A * B.col1, A * B.col2);
}

/*float*/ function AbsS(/*float*/ a)
{
  return a > 0.0 ? a : -a;
}

/*Vec2*/ function AbsV(/*Vec2 &*/ a)
{
  return new Vec2(fabsf(a.x), fabsf(a.y));
}

/*Vec2*/ function AbsM(A)
{
  return new Mat22(Abs(A.col1), Abs(A.col2));
}

/*float*/ function SignS(/*float*/ x)
{
  return x < 0.0 ? -1.0 : 1.0;
}

/*float*/ function MinSS(/*float*/ a, /*float*/ b)
{
  return a < b ? a : b;
}

/*float*/ function MaxSS(/*float*/ a, /*float*/ b)
{
  return a > b ? a : b;
}

/*float*/ function ClampSSS(/*float*/ a, /*float*/ low, /*float*/ high)
{
  return Max(low, Min(a, high));
}

/*void*/ function Swap(obj)
{
  var tmp = obj.a;
  obj.a = obj.b;
  obj.b = tmp;
}

// Random number in range [-1,1]
/*float*/ function Random()
{
  /*float*/ var r = /*float*/ Math.random();
  r /= Number.MAX_SAFE_INTEGER;
  r = 2.0 * r - 1.0;
  return r;
}

/*float*/function  Random(/*float*/ lo, /*float*/ hi)
{
  /*float*/ var r = /*float*/ rand();
  r /= Number.MAX_SAFE_INTEGER;
  r = (hi - lo) * r + lo;
  return r;
}
