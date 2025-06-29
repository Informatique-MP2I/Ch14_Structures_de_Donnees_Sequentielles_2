let load_csv filename =
  [||]


let is_magic_square square =
  let n = Array.length square in 
  (* Main diagonal *)
  let rec sum_main_diag acc i =
    if i=n then
      acc
    else
      sum_main_diag (acc+square.(i).(i)) (i+1) in
  let sum = sum_main_diag 0 0 in
  (* Second diagonal *)
  let rec sum_sec_diag acc i =
    if i=n then
      acc
    else
      sum_sec_diag (acc+square.(i).(n-1-i)) (i+1) in
  if sum <> sum_sec_diag 0 0 then
    false
  else
    (* lines *)
    let rec sum_line line j =
      if j = n then
        0
      else
        line.(j) + sum_line line (j+1) in
    if not (Array.for_all (fun line -> sum = sum_line line 0) square) then
      false
    else
      (* columns  = lines of the transposed matrix *)
      let t_square = Array.init n (fun j -> (Array.init n (fun i -> square.(i).(j)))) in
      if not (Array.for_all (fun line -> sum = sum_line line 0) t_square) then
        false
      else
        true

let () =
  if Array.length Sys.argv <> 2 then
    begin
      Printf.printf "Usage : %s <filename.csv>\n" Sys.argv.(0);
      exit 1
    end
  else
    let filename = Sys.argv.(1) in
    try
      let square = load_csv filename in
      if is_magic_square square then
        Printf.printf "Yes, it's a magic square !\n"
      else
        Printf.printf "No, try again.\n"
    with
    | Sys_error err -> Printf.eprintf "Error : %s\n" err
  
