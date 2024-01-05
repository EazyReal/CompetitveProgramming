(* helper functions *)
(* let print_array a = Array.iter (Printf.printf "%d ") a; Printf.printf "\n" *)

(* invariant: (l, r) is the things that I am not sure if satisfy p *)
let rec binary_search l r p = 
  if l+1 < r then
    let m = (l + r) / 2 in
    if p m then
      binary_search m r p
    else
      binary_search l m p
  else l

let solve q pre =
  binary_search 0 (Array.length pre) (fun i -> pre.(i) <= q)

let () = 
  let n, nq = Scanf.sscanf (read_line ()) "%d %d" (fun x y -> x, y) in
  let a = Array.init n (fun _ -> Scanf.scanf "%d%c" (fun x _ -> x)) in 
  Array.sort compare a;
  let pre = Iter.of_array a |> Iter.scan (+) 0 |> Iter.to_array in 
  (* print_array pre; *)
  Iter.(1 -- nq) |> Iter.iter @@ fun _ ->
    let q = Scanf.scanf "%d\n" Fun.id in
    Printf.printf "%d\n" @@ solve q pre