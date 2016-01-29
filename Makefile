.PHONY: clean All

All:
	@echo "----------Building project:[ UVa-459 - Debug ]----------"
	@cd "UVa-459" && "$(MAKE)" -f  "UVa-459.mk"
clean:
	@echo "----------Cleaning project:[ UVa-459 - Debug ]----------"
	@cd "UVa-459" && "$(MAKE)" -f  "UVa-459.mk" clean
