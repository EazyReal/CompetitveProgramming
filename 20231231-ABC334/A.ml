let () = 
  let b, g = Scanf.scanf "%d %d\n" (fun b g -> b, g) in
  Printf.printf "%s\n" (if b > g then "Bat" else "Glove")