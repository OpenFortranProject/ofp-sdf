[
   Header                        -- H hs=0 [_1],

   Struct                        -- V [H hs=0["#ifndef _" _1 "_OCR_H"] 
                                    "#include <inttypes.h>"
                                    "#include <ocr.h>"
                                    ""
                                    H hs=0["struct " _1 "_mod_t {"] 
                                    _2
                                    "};"
                                    ""
                                    H hs=0["#define _" _1 "_OCR_H"] 
                                    "#endif"
                                      ],
   OcrSizeOf                     -- H hs=0["#define " _1 " sizeof("_2 ")"],

   OcrDefine                     -- H hs=0["#define " _1 " (("_2 ")" _3 ")"],
   OcrDecl                       -- H hs=0["  " _2 " " _1 "[" _3 "];"],
   char                          -- "char",
   int                           -- "int",
   int                           -- H hs=0 ["int" _1 "_t"],
   double                        -- "double",
   no-init                       -- "",

   #EOF                          --
]
