type goldenRatio = {
  n : int;
  ratioFibonacci : float;
  errorFibonacci : float;
  ratioLucas : float;
  errorLucas : float;
  goldenSequence : float;
  errorGoldenSequence : float
}

let ratioFibonacci n =
  assert(n > 0);
  let rec fib n =
    match n with
    | 0 -> 0;
    | 1 -> 1;
    | _ -> fib (n-1) + fib (n-2) in
  float_of_int (fib (n+1)) /. float_of_int (fib n)

let ratioLucas n =
  assert(n >= 0);
  let rec lucas n =
    match n with
    | 0 -> 2;
    | 1 -> 1;
    | _ -> lucas (n-1) + lucas (n-2) in
  float_of_int (lucas (n+1)) /. float_of_int (lucas n)

let rec goldenSequence n =
  assert (n>=0);
  match n with
  | 0 -> 1.
  | _ -> 1. +. 1. /. (goldenSequence (n-1))

let createGoldenRatio n =
  let goldenRatio = (1. +. (sqrt 5.)) /. 2. in
  let ratioFibonacci = ratioFibonacci n in
  let errorFibonacci = abs_float (goldenRatio -. ratioFibonacci) in
  let ratioLucas = ratioLucas n in
  let errorLucas = abs_float (goldenRatio -. ratioLucas) in
  let goldenSequence = goldenSequence n in
  let errorGoldenSequence = abs_float (goldenRatio -. goldenSequence) in
  {n = n;
   ratioFibonacci = ratioFibonacci;
   errorFibonacci = errorFibonacci;
   ratioLucas = ratioLucas;
   errorLucas = errorLucas; 
   goldenSequence = goldenSequence;
   errorGoldenSequence = errorGoldenSequence}

let rec convList first last =
  if first > last then
    []
  else
    let conv = createGoldenRatio first in
    conv :: convList (first + 1) last  

let save_csv filename convList =
  let endOfColumn = ',' in
  let endOfLine = '\n' in
  try
    let oc = open_out filename in
    Printf.fprintf oc "Rang%c" endOfColumn;
    Printf.fprintf oc "RatioFib%c" endOfColumn;
    Printf.fprintf oc "ErrFib%c" endOfColumn;
    Printf.fprintf oc "RatioLucas%c" endOfColumn;
    Printf.fprintf oc "ErrLucas%c" endOfColumn;
    Printf.fprintf oc "GoldenSeq%c" endOfColumn;
    Printf.fprintf oc "ErrGoldenSeq%c" endOfLine;
    List.iter (fun c ->
        Printf.fprintf oc "%d%c" c.n endOfColumn;
        Printf.fprintf oc "%.6f%c" c.ratioFibonacci endOfColumn;
        Printf.fprintf oc "%.6f%c" c.errorFibonacci endOfColumn;
        Printf.fprintf oc "%.6f%c" c.ratioLucas endOfColumn;
        Printf.fprintf oc "%.6f%c" c.errorLucas endOfColumn;
        Printf.fprintf oc "%.6f%c" c.goldenSequence endOfColumn;
        Printf.fprintf oc "%.6f%c" c.errorGoldenSequence endOfLine;
      ) convList;
    close_out oc
  with
  | Sys_error err -> Printf.eprintf "Error : %s\n" err
                       
(* main *)
let () =
  if Array.length Sys.argv <> 4 then
    begin
      Printf.printf "Usage : %s first last filename\n" Sys.argv.(0);
      exit 1
    end
  else
    let first = int_of_string Sys.argv.(1) in
    let last = int_of_string Sys.argv.(2) in
    let filename = Sys.argv.(3) ^ ".csv" in
    let convList = convList first last in
    save_csv filename convList;
    Printf.printf "Data has been saved in the file '%s'.\n" filename
