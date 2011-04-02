all: carts

carts:
	cd src; make;

clean:
	rm -f cart_manager
	cd src; make clean;
