fun reverse (s::xs:int list)= reverse(xs) @ [s]
|	reverse ([])=[]

fun rev (s::xs,y)=rev(xs,s::y)
|	rev ([],ys)=ys
fun reverse' x:int list=rev(x,[])

fun interleave(x,[]):int list=x
|	interleave([],y)=y
|	interleave(a::xs,b::ys)=(a::[b])@interleave(xs,ys)

datatype tree=Empty | Node of tree * int * tree
fun listToTree []=Empty
|	listToTree xs=let val k=length xs div 2
in  Node(listToTree(List.take(xs,k)),List.nth(xs,k),listToTree(List.drop(xs,k+1))) end

fun trav Empty=[]
| 	trav (Node(t1,x,t2))=trav t1 @ [x] @ trav t2
fun revT Empty=Empty
|	revT (Node(t1,x,t2))=Node(revT(t2),x,revT(t1))

fun binarySerach (Empty,k:int):bool=false
|	binarySerach(Node(t1,x,t2),k:int)=case Int.compare(x,k) of
	GREATER => binarySerach(t1,k)
|	EQUAL   => true
|	LESS  	=> binarySerach(t2,k);
trav(listToTree [1,2,3,4,5,6,7])=[1,2,3,4,5,6,7];
trav(revT(listToTree [1,2,3,4,5,6,7]))=reverse(trav(listToTree [1,2,3,4,5,6,7]));
binarySerach(listToTree [1,2,3,4],2);