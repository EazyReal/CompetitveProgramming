open List

let n, k = Scanf.sscanf (read_line ()) " %d %d" (fun a b  -> a, b)
let a = List.init k @@ fun _ -> Scanf.scanf " %d" (fun a -> a)

let memoize f =
  let cache = Hashtbl.create 200020 in
  fun x ->
    match Hashtbl.find_opt cache x with
    | Some x  ->
      (* print_endline "cache"; *)
      x
    | None    ->
      let y = f x in
      Hashtbl.add cache x y;
      y

let fix f =
  let rec aux = lazy (memoize @@ fun x -> f (Lazy.force aux) x) in
  Lazy.force aux

let cost_even_aux self a = 
  match a with 
    | x::y::xs ->
      y-x + (self xs)
    | _ -> 0

let cost_even = fix cost_even_aux

let rec cost_odd a taken = 
  if taken then cost_even a
  else 
    match a with 
      | x::y::xs ->
        let drop = cost_even @@ y::xs in
        let take = y-x + (cost_odd xs false) in 
        min take drop
      | _ -> 0

let cost a = 
  match List.length a mod 2 with
    | 0 -> cost_even a
    | _ -> cost_odd a false

let () = 
    Printf.printf "%d\n" @@ cost a