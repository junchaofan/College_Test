3+ 4;
(*3 + 2.0;*)(*实数与整数不能直接相加*)
it + 6;
val it = "hello";
(*it + " world";字符串应该使用^连接符*)
(*it + 5;类型不一致*)
val a = 5;
a = 6;
a + 8; 
val twice = (fn x => 2 * x);
twice a;
let (*val*) x = 1 in x end;(*let后必须加入声明*)
(*foo; 没有类型声明*)
[1, "foo"];(*两个类型不一致，[1]为int list型，["foo"]为string list型*)

fun mult []=1
	| mult(x::L)=x*(mult L);
	
fun mult []=1
	| mult(x::L)=x*(mult L);
fun Mult []=1
	| Mult(r::R)=mult(r)*Mult(R);

(* mult’ : int list * int -> int 			*)
(* REQUIRES: true				*)
(* ENSURES: mult’(L, a)  实现整数列表每个整数与a的连乘*)

fun mult' ([],a) = a
	| mult'(x :: L, a) = mult' (L, x * a);
fun Mult' ([],a) = a
	| Mult'(r::R,a)=Mult'(R,mult'(r,a));
	
fun double (0 : int) : int = 0
    | double n = 2 + double (n - 1)

fun square (0 : int) : int = 0
	| square n = square(n-1) + double(n-1) + 1;
	
fun divisibleByThree (0 : int) : bool = true
  	    | divisibleByThree 1 = false
		| divisibleByThree 2 = false
  	    | divisibleByThree n = divisibleByThree (n - 3);
		
fun oddP (0 : int) : bool = false
  	    | oddP 1 = true
  	    | oddP n = oddP (n - 2);