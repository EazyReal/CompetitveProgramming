let a, m, l, r = Scanf.sscanf (read_line ()) "%d %d %d %d" (fun a b c d -> a, b, c, d)

let tree_between x d = 
  let q = x / d in
  if x >= 0 || x mod d = 0 then q else q - 1

let () = 
  let tree2l = tree_between (l-a-1) m in
  let tree2r = tree_between (r-a) m in 
  (* print_int @@ tree2l; print_newline ();
  print_int @@ tree2r; print_newline (); *)
  tree2r - tree2l |> print_int ; print_newline ()