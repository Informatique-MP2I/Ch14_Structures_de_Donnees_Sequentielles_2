(* Binary deserialization function for booleans *)
let deserialize_bool input_channel =
  match read_byte input_channel with
  | Some 0 -> false
  | Some _ -> true
  | None -> failwith "Unexpected end of file.\n"
(* Binary deserialization function for integers *)
let deserialize_int input_channel =
  let rec aux n acc shift =
    if n = 0 then acc
    else match read_byte input_channel with
         | Some b -> aux (n-1) (acc lor (b lsl shift)) (shift+8)
         | None -> failwith "Unexpected end of file.\n"
  in
  aux 4 0 0  
(* Binary deserialization function for a string *)
let deserialize_string input_channel =
  let rec aux acc =
    match read_byte input_channel with
    | Some 0 -> acc  
    | Some b -> aux (acc ^ String.make 1 (Char.chr b))
    | None -> failwith "Unexpected end of file.\n"
  in
  aux ""
