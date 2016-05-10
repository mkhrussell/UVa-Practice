.PHONY: clean All

All:
	@echo "----------Building project:[ UVa-11953 - Debug ]----------"
	@cd "UVa-11953" && "$(MAKE)" -f  "UVa-11953.mk"
clean:
	@echo "----------Cleaning project:[ UVa-11953 - Debug ]----------"
	@cd "UVa-11953" && "$(MAKE)" -f  "UVa-11953.mk" clean
