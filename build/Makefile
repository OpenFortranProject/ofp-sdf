buildloc=${HOME}/tst/stratbuild
ATERM=aterm-2.6
SDF=sdf2-bundle-2.6
STRAT=strategoxt-0.17
ATERMURL=http://releases.strategoxt.org/aterm64/aterm-2.6pre24721-hl4j0mla/${ATERM}.tar.gz
SDFURL=http://releases.strategoxt.org/sdf2-bundle-with-aterm64/sdf2-bundle-2.6pre364564-rsarp9qh/${SDF}.tar.gz
STRATURL=http://releases.strategoxt.org/strategoxt/strategoxt-0.17pre19210-3wyrxd7y/${STRAT}pre19210.tar.gz
CFLAGS=
#-m32

all: clean aterm sdf stratego

clean: new
	rm -rf ${buildloc}

new:
	rm -rf ${ATERM}
	rm -rf ${SDF}
	rm -rf ${STRAT}

download:
	wget ${ATERMURL}
	wget ${SDFURL}
	wget ${STRATURL}
	mv ${STRAT}pre19210.tar.gz ${STRAT}.tar.gz

aterm: new
	tar xf ${ATERM}.tar.gz
	@echo "======= INSTALLING ATERM ======="
	@echo "cd ${ATERM}; ./configure --prefix=${buildloc}/aterm CFLAGS=${CFLAGS}; make; make install;"
	cd ${ATERM}; ./configure --prefix=${buildloc}/aterm CFLAGS=${CFLAGS}; make; make install;
	@echo "======= DONE ATERM ======="


sdf:
	tar xf ${SDF}.tar.gz
	@echo "======= INSTALLING SDF ======="
	@echo "cd ${SDF}; ./configure --prefix=${buildloc}/sdf2 --with-aterm=${buildloc}/aterm CFLAGS=${CFLAGS}; make #; make install"
	export PATH=${buildloc}/aterm/bin:$PATH
	@echo "++++++++++PATH IS ${PATH}"
	cd ${SDF}; ./configure --prefix=${buildloc}/sdf2 --with-aterm=${buildloc}/aterm CFLAGS=${CFLAGS}; make; make install
	@echo "======= DONE SDF ======="

stratego:
	tar xf ${STRAT}.tar.gz
	@echo "======= INSTALLING STRAT ======="
	@echo "cd ${STRAT}; ./configure --prefix=${buildloc}/stratego --with-aterm=${buildloc}/aterm --with-sdf=${buildloc}/sdf2/ CFLAGS=${CFLAGS}; make; make install"
	cd ${STRAT}pre19210; ./configure --prefix=${buildloc}/stratego --with-aterm=${buildloc}/aterm --with-sdf=${buildloc}/sdf2/ CFLAGS=${CFLAGS}; make; make install
	@echo "======= DONE STRAT ======="
