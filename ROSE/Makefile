all: SgUntyped.str

SgUntyped.str: SgUntyped.rtg
	rtg2sig -i SgUntyped.rtg -o SgUntyped.str

SgUntyped.rtg.aterm: SgUntyped.rtg
	parse-rtg -i SgUntyped.rtg | pp-aterm -o SgUntyped.rtg.aterm
