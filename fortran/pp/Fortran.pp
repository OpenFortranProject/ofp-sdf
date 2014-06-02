[
   Comment                       -- _1,
   None                          -- ,
   Label                         -- _1,
   REAL                          -- KW["REAL ::"],
   INTEGER                       -- KW["INTEGER ::"],

   #R201 --,
   ofpProgram                    -- _1 _2,
   ofpProgram.1:opt              -- ,

   #R204 --,
   ofpSpecPart                   -- H hs=0[_1],

   #R208 --,
   ofpExecPart                   -- H hs=0[_1],
   ofpFuncPart                   -- H hs=0[_1],

   #R303 --,
   ofpName                       -- H hs=1[_1],
   ofpEndProgramStmt             -- H hs=1[_1 "END PROGRAM"  _2],

   #R404 --,
   ofpType                       -- H hs=1[_1 _2],

   #R407 --,
   ofpLiteral                    -- H hs=1[_1 _2],

   #R501 --,
   ofpTypeDeclarationStmt        -- H hs=1[H hs=3[_1] _2 _3 _4],

   #R502 --,
   Some                          -- _1,
   Some                          -- _1 _2,
   
   #R503 --,
   ofpEntityDecl                 -- _1 _2 _3 _4 _5,

   #R602 --,
   ofpVarDef                     -- _1,

   #R732 --,
   ofpAssignmentStmt             -- H hs=1[H hs=3[_1] _2 KW["="] _3],
   ofpAssignmentStmt.2:op        -- ,

   #R1101 --,
   ofpMainProgram                -- V[H[_1] _2],
   ofpMainProgram.1:opt          -- ,

   #R1102 --,
   ofpProgramStmt                --  _1 KW["PROGRAM"] _2,
   
   #R1205 --,
   ofpScope                      -- V vs=1 is=0[H hs=1[_4] _1 _2 _3 _5 _6]

]
