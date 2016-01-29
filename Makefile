.PHONY: clean All

All:
	@echo "----------Building project:[ UVa-11902 - Debug ]----------"
	@cd "UVa-11902" && "$(MAKE)" -f  "UVa-11902.mk"
clean:
	@echo "----------Cleaning project:[ UVa-11902 - Debug ]----------"
	@cd "UVa-11902" && "$(MAKE)" -f  "UVa-11902.mk" clean
