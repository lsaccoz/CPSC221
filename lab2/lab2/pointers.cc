int main () {
  int x = 5, y = 15;
  int * p1, *p2;
		// value of	x	y	p1	p2
		//		5	15	uninit	uninit
  p1 = &x;
                //              5       15      -> x    uninit
  p2 = &y;
                //              5       15      -> x    -> y
  *p1 = 6;
                //              6       15      -> x    -> y
  *p1 = *p2;
                //              15      15      -> x    -> y
  p2 = p1;
                //              15      15      -> x    -> x
  *p1 = *p2+10;
                //              25      15      -> x    -> x
  return 0;
}
