.PHONY: clean All

All:
	@echo "----------Building project:[ UVa-10935 - Debug ]----------"
	@cd "UVa-10935" && "$(MAKE)" -f  "UVa-10935.mk"
clean:
	@echo "----------Cleaning project:[ UVa-10935 - Debug ]----------"
	@cd "UVa-10935" && "$(MAKE)" -f  "UVa-10935.mk" clean
