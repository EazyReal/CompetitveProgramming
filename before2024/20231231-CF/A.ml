open List

let rec init i last f =
  if i > last then []
  else if i = last then [f i]
  else
    let r1 = f i in
    let r2 = f (i+1) in
    r1 :: r2 :: init (i+2) last f

let init len f =
  if len < 0 then invalid_arg "List.init" else
  init 0 (len - 1) f

let find_missing b k target =
  let prod_b = List.fold_left (fun x y -> if x * y <= 2023 then x * y else 2024) 1 b in
  match (target mod prod_b) with
    | 0 -> Some (init k (fun i -> if i == 0 then target / prod_b else 1))
    | _ -> None

let () =
  let t = read_int () in
  for _ = 1 to t do
    let n, k = Scanf.scanf "%d %d\n" (fun x y -> x, y) in
    let b = init n (fun i -> (Scanf.scanf "%d%c") (fun x _ -> x)) in
    let missing = find_missing b k 2023 in
    match missing with
    | Some xs ->
       Printf.printf "YES\n";
       List.iteri (fun i x -> Printf.printf "%d%c" x (if i != k-1 then ' ' else '\n') ) xs
    | None -> Printf.printf "NO\n"
  done
