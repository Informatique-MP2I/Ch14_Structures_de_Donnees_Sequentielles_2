let () =
  let input_channel = open_in_bin "test.bin" in
  let b = deserialize_bool input_channel in
  let n = deserialize_int input_channel in
  let s = deserialize_string input_channel in
  Printf.printf "Bool: %b\n" b;
  Printf.printf "Int: %d\n" n;
  Printf.printf "String: %s\n" s;
  (* close the file *)
  close_in input_channel
