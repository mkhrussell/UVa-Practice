.PHONY: clean All

All:
	@echo "----------Building project:[ UVa-796 - Debug ]----------"
	@cd "UVa-796" && "$(MAKE)" -f  "UVa-796.mk"
clean:
	@echo "----------Cleaning project:[ UVa-796 - Debug ]----------"
	@cd "UVa-796" && "$(MAKE)" -f  "UVa-796.mk" clean
