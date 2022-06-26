#![allow(dead_code, mutable_transmutes, non_camel_case_types, non_snake_case,
    non_upper_case_globals, unused_assignments, unused_mut)]
#![register_tool(c2rust)]
#![feature(const_raw_ptr_to_usize_cast, main, register_tool)]
extern "C" {
#[no_mangle]
fn malloc(_: libc::c_ulong) -> *mut libc::c_void;
#[no_mangle]
fn free(__ptr: *mut libc::c_void);
#[no_mangle]
fn printf(_: *const libc::c_char, _: ...) -> libc::c_int;
#[no_mangle]
fn scanf(_: *const libc::c_char, _: ...) -> libc::c_int;
}
#[derive(Copy, Clone)]
#[repr(C)]
pub struct process {
pub id: *mut libc::c_int,
pub avl: libc::c_int,
pub total_cpu: libc::c_int,
pub tot_rem: libc::c_int,
pub start_t: libc::c_int,
pub end_t: libc::c_int,
pub ta_time: libc::c_int,
pub done: bool,
pub start_b: bool,
}
// note: if start_t is NULL, its not scheduled, use boolean start_b if need be
pub type pb = process;
#[no_mangle]
pub static mut numProcs: libc::c_int = 0;
#[no_mangle]
pub static mut cycles: libc::c_int = 0 as libc::c_int;
#[no_mangle]
pub static mut PB: *mut process = 0 as *const process as *mut process;
#[no_mangle]
pub unsafe extern "C" fn prt() {
printf(b"ID      Arrival Total   Start   End     Turnaround\n\x00" as
          *const u8 as *const libc::c_char);
printf(b"--------------------------------------------------\n\x00" as
          *const u8 as *const libc::c_char);
let mut b: libc::c_int = 0 as libc::c_int;
while b < numProcs {
   if !(*PB.offset(b as isize)).id.is_null() {
       printf(b"%d\t\x00" as *const u8 as *const libc::c_char,
              *(*PB.offset(b as isize)).id);
       printf(b"%d\t\x00" as *const u8 as *const libc::c_char,
              (*PB.offset(b as isize)).avl);
       printf(b"%d\t\x00" as *const u8 as *const libc::c_char,
              (*PB.offset(b as isize)).total_cpu);
       // printf("%d\t %d\t %d\t", *(PB[b].id), PB[b].avl, PB[b].total_cpu);
       if (*PB.offset(b as isize)).done {
           printf(b"%d\t\x00" as *const u8 as *const libc::c_char,
                  (*PB.offset(b as isize)).start_t); // nest if ends
           printf(b"%d\t\x00" as *const u8 as *const libc::c_char,
                  (*PB.offset(b as isize)).end_t);
           printf(b"%d\t\x00" as *const u8 as *const libc::c_char,
                  (*PB.offset(b as isize)).ta_time);
       }
       printf(b"\n\x00" as *const u8 as *const libc::c_char);
   }
   b += 1
};
}
// end print
#[no_mangle]
pub unsafe extern "C" fn entParms() {
// printf("Enter total number of processes: ");
// scanf("%d", &numProcs);
printf(b"Enter total number of processes: \x00" as *const u8 as
          *const libc::c_char);
scanf(b"%d\x00" as *const u8 as *const libc::c_char,
     &mut numProcs as *mut libc::c_int);
PB =
   malloc((numProcs as
               libc::c_ulong).wrapping_mul(::std::mem::size_of::<pb>() as
                                               libc::c_ulong)) as
       *mut pb;
// printf("%d\n", sizeof(PB));
let mut b: libc::c_int = 0 as libc::c_int;
while b < numProcs {
   let mut z: libc::c_int = 0;
   printf(b"Enter process id: \x00" as *const u8 as *const libc::c_char);
   scanf(b"%d\x00" as *const u8 as *const libc::c_char,
         &mut z as *mut libc::c_int);
   let ref mut fresh0 = (*PB.offset(b as isize)).id;
   *fresh0 =
       malloc((1 as libc::c_int as
                   libc::c_ulong).wrapping_mul(::std::mem::size_of::<libc::c_int>()
                                                   as libc::c_ulong)) as
           *mut libc::c_int;
   *(*PB.offset(b as isize)).id = z;
   // printf("curr tot cpu %d\n" , PB[z].total_cpu);
   printf(b"Enter arrival cycle for process P[%d]: \x00" as *const u8 as
              *const libc::c_char, *(*PB.offset(b as isize)).id);
   scanf(b"%d\x00" as *const u8 as *const libc::c_char,
         &mut (*PB.offset(b as isize)).avl as *mut libc::c_int);
   printf(b"Enter total cycles for process P[%d]: \x00" as *const u8 as
              *const libc::c_char, *(*PB.offset(b as isize)).id);
   scanf(b"%d\x00" as *const u8 as *const libc::c_char,
         &mut (*PB.offset(b as isize)).total_cpu as *mut libc::c_int);
   (*PB.offset(b as isize)).done = 0 as libc::c_int != 0;
   b += 1
}
printf(b"\n\x00" as *const u8 as *const libc::c_char);
prt();
}
// printf("curr id %d\n", *(PB[b].id));
// printf("curr avl %d\n" , PB[z].avl);
// end of entparms
// return a boolean false if everything is scheduled, returns true if something is not scheduled
#[no_mangle]
pub unsafe extern "C" fn checkSchedule() -> bool {
let mut c: libc::c_int = 0 as libc::c_int;
loop  {
   if c == numProcs { return 0 as libc::c_int != 0 }
   if !(*PB.offset(c as isize)).done { return 1 as libc::c_int != 0 }
   c += 1
   //;)
};
// end while
}
// end func
//------------------------------------------------------------------
// returns the earliest process not already done
#[no_mangle]
pub unsafe extern "C" fn currNS() -> *mut pb {
let mut earliest: *mut pb =
   malloc((1 as libc::c_int as
               libc::c_ulong).wrapping_mul(::std::mem::size_of::<pb>() as
                                               libc::c_ulong)) as
       *mut pb; // end for
(*earliest).avl = 2147483647 as libc::c_int;
let mut b: libc::c_int = 0 as libc::c_int;
while b < numProcs {
   if (*PB.offset(b as isize)).avl < (*earliest).avl &&
          !(*PB.offset(b as isize)).done {
       earliest = &mut *PB.offset(b as isize) as *mut process
   }
   b += 1
}
return earliest;
}
// end of process
#[no_mangle]
pub unsafe extern "C" fn fifo() {
// point of start for any process is the current cycle time
// take the process with earliest arrival time that has not been done
//       take the total cycle time of that process, ---> arrival time + cycle time of process = end time\
//set done flag of current process to 1
// cycle time += end time
// if not at PB[numProcs], PB[next process].start = current time
cycles = 0 as libc::c_int;
let mut b: libc::c_int = 0 as libc::c_int;
while b < numProcs {
   (*PB.offset(b as isize)).done = 0 as libc::c_int != 0;
   b += 1
}
while checkSchedule() {
   (*currNS()).start_t = cycles;
   (*currNS()).end_t = (*currNS()).start_t + (*currNS()).total_cpu;
   (*currNS()).ta_time = (*currNS()).end_t - (*currNS()).avl;
   cycles += (*currNS()).total_cpu;
   (*currNS()).done = 1 as libc::c_int != 0
}
prt();
}
// end fifo
//-------------------------------------------------------------------
#[no_mangle]
pub unsafe extern "C" fn currSJ() -> *mut pb {
let mut shortest: *mut pb =
   malloc((1 as libc::c_int as
               libc::c_ulong).wrapping_mul(::std::mem::size_of::<pb>() as
                                               libc::c_ulong)) as
       *mut pb; // end for
(*shortest).total_cpu = 2147483647 as libc::c_int;
let mut b: libc::c_int = 0 as libc::c_int;
while b < numProcs {
   if (*PB.offset(b as isize)).total_cpu < (*shortest).total_cpu &&
          (*PB.offset(b as isize)).avl <= cycles &&
          !(*PB.offset(b as isize)).done {
       shortest = &mut *PB.offset(b as isize) as *mut process
   }
   b += 1
}
return shortest;
}
// end of process
#[no_mangle]
pub unsafe extern "C" fn sjf() {
// orders from smallest to largest turnaround
cycles = 0 as libc::c_int;
// int curr_star = cycles;
let mut b: libc::c_int = 0 as libc::c_int; // end for
while b < numProcs {
   (*PB.offset(b as isize)).done = 0 as libc::c_int != 0;
   b += 1
}
while checkSchedule() {
   let mut curr: *mut pb = currSJ();
   (*curr).start_t = cycles;
   (*curr).end_t = (*curr).start_t + (*curr).total_cpu;
   (*curr).ta_time = (*curr).end_t - (*curr).avl;
   cycles += (*curr).total_cpu;
   (*curr).done = 1 as libc::c_int != 0
}
prt();
}
#[no_mangle]
pub unsafe extern "C" fn currSRT() -> *mut pb {
let mut shortest: *mut pb =
   malloc((1 as libc::c_int as
               libc::c_ulong).wrapping_mul(::std::mem::size_of::<pb>() as
                                               libc::c_ulong)) as
       *mut pb;
(*shortest).tot_rem = 2147483647 as libc::c_int;
let mut b: libc::c_int = 0 as libc::c_int;
while b < numProcs {
   if (*PB.offset(b as isize)).tot_rem < (*shortest).tot_rem &&
          (*PB.offset(b as isize)).avl <= cycles &&
          !(*PB.offset(b as isize)).done {
       shortest = &mut *PB.offset(b as isize) as *mut process
   }
   b += 1
}
return shortest;
}
// end currSRT
#[no_mangle]
pub unsafe extern "C" fn srt() {
cycles = 0 as libc::c_int; // end for
let mut b: libc::c_int = 0 as libc::c_int;
while b < numProcs {
   let ref mut fresh1 = (*PB.offset(b as isize)).start_b;
   *fresh1 = 0 as libc::c_int != 0;
   (*PB.offset(b as isize)).done = *fresh1;
   (*PB.offset(b as isize)).tot_rem = (*PB.offset(b as isize)).total_cpu;
   b += 1
}
// printf("\nID            -->> %d -- %d %d %d\n" ,*(cSRT->id) ,*(PB[0].id), *(PB[1].id), *(PB[2].id));
   // printf("START_T CHECK -->> %d %d %d\n", PB[0].start_t, PB[1].start_t, PB[2].start_t);
   // printf("TOT REM CHECK -->> %d %d %d\n", PB[0].tot_rem, PB[1].tot_rem, PB[2].tot_rem);
while checkSchedule() {
   let mut cSRT: *mut pb = currSRT(); // while ends
   if !(*cSRT).start_b {
       (*cSRT).start_t = cycles; // end if
       (*cSRT).start_b = 1 as libc::c_int != 0
   }
   (*cSRT).tot_rem -= 1;
   cycles += 1;
   if (*cSRT).tot_rem == 0 {
       (*cSRT).end_t = cycles;
       (*cSRT).ta_time = (*cSRT).end_t - (*cSRT).avl;
       (*cSRT).done = 1 as libc::c_int != 0
   }
}
prt();
}
// end srt
#[no_mangle]
pub unsafe extern "C" fn quit() {
let mut b: libc::c_int = 0 as libc::c_int;
while b < numProcs {
   let ref mut fresh2 = (*PB.offset(b as isize)).id;
   *fresh2 = 0 as *mut libc::c_int;
   free((*PB.offset(b as isize)).id as *mut libc::c_void);
   b += 1
}
PB = 0 as *mut process;
free(PB as *mut libc::c_void);
}
unsafe fn main_0() -> libc::c_int {
let mut c: libc::c_int = 0;
while c != 5 as libc::c_int {
   printf(b"\nBatch Scheduling\n\x00" as *const u8 as
              *const libc::c_char);
   printf(b"--------------------------------\n\x00" as *const u8 as
              *const libc::c_char);
   printf(b"1) Enter parameters\n\x00" as *const u8 as
              *const libc::c_char);
   printf(b"2) Schedule processes with FIFO algorithm\n\x00" as *const u8
              as *const libc::c_char);
   printf(b"3) Schedule processes with SJF algorithm\n\x00" as *const u8
              as *const libc::c_char);
   printf(b"4) Schedule processes with SRT algorithm\n\x00" as *const u8
              as *const libc::c_char);
   printf(b"5) Quit and free memory\n\n\x00" as *const u8 as
              *const libc::c_char);
   printf(b"Enter selection: \x00" as *const u8 as *const libc::c_char);
   scanf(b"%d\x00" as *const u8 as *const libc::c_char,
         &mut c as *mut libc::c_int);
   match c {
       1 => { entParms(); }
       2 => { fifo(); }
       3 => { sjf(); }
       4 => { srt(); }
       5 => { quit(); }
       _ => {
           printf(b"not a choice\x00" as *const u8 as
                      *const libc::c_char);
       }
   }
}
return 1 as libc::c_int;
/* indicates success */
}
#[main]
pub fn main() { unsafe { ::std::process::exit(main_0() as i32) } }
/*

1
3
1
0
6
2
1
3
3
3
2
2
3
4
5

*/
