(* Reads a byte from a given file *)
let read_byte input_channel =
  try
    Some (input_byte input_channel)
  with
    End_of_file -> None
