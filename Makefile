.PHONY: clean All

All:
	@echo "----------Building project:[ UVa-11727 - Debug ]----------"
	@cd "UVa-11727" && "$(MAKE)" -f  "UVa-11727.mk"
clean:
	@echo "----------Cleaning project:[ UVa-11727 - Debug ]----------"
	@cd "UVa-11727" && "$(MAKE)" -f  "UVa-11727.mk" clean
