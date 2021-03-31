fun Add m = m+m
fun thenAddOne (Add,n:int)=Add n+1
val test1=thenAddOne (Add,2);

fun mapList (Add,[]) = []
   |mapList (Add,x::L) = (Add x)::mapList(Add,L)
val test2=mapList(Add,[1,2,4,6,7]);
   
fun mapList' Add = let fun AddList L = case L of []=>[]
| x::L=>Add(x)::AddList(L) (*mapList(Add,L)*)
  in AddList end;
val test3=mapList' Add [1,2,4,6,7];
 
datatype 'a option = NONE | SOME of 'a
datatype 'a tree = Empty | Node of ('a tree) * 'a * ('a tree)
fun findOdd []=NONE
  | findOdd (x::L)=if x mod 2 = 1 then SOME(x)
  else findOdd L;
val test4=findOdd [0,2,4,6,7,8]; 

fun map f [] = []   
  | map f (x::R) = (f x) :: (map f R)

fun sublists [] = [[]]
  | sublists (x::R) = 
    let 
	    val S = sublists R
	in  
	    S @ map(fn A => x::A) S
	end

fun sum [] = 0
  | sum (x::xs) = x+sum(xs)

fun deal ([],s) = []
  | deal (x::L,s)  = if sum x = s then x
					 else deal(L,s)

fun subsetSumOption ([],s) = NONE
  | subsetSumOption (L,s) = 
    let 
		val S = deal(sublists L,s) 
	in 	
		if sum S = s then SOME(S)
		else NONE end;

val test5=subsetSumOption([1,2,3,4,5,6],12);

fun exists P = 
	let
		fun find L = case L of
			[] => false
		|	x::L => if P x = true then true
					else find L
	in find end;
fun forall P = 
	let
		fun find L = case L of
			[] => true
		|	x::L => if P x = true then find L
					else false
	in find end;

fun exists' P L= foldr(fn (x,y)=>P(x) orelse y) false L;
fun forall' P L= foldr(fn (x,y)=>P(x) andalso y) true L; 
val test6=exists(fn x=>if x mod 2 = 1 then true else false) [1,2,3,4,5];
val tset7=forall(fn y=>if y mod 2 = 1 then true else false) [1,3,5,7,9];
val test16'=exists'(fn x=>x mod 2 = 1) [1,2,3,4,5];
val tset17'=forall'(fn y=>y mod 2 = 1) [1,3,5,7,9];
 
fun treeFilter P =
	let
		fun change L = case L of 
			Empty => Empty
		|	Node(t1,x,t2) => if P x = true then Node(change(t1),SOME(x),change(t2))
							else Node(change(t1),NONE,change(t2))
	in change end;

val P= fn m => m mod 2 = 1;
val test8 = treeFilter P Empty;
val test9=treeFilter P (Node(Empty,1,Node(Empty,2,Empty)));

