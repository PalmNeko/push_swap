
clean:
	$(RM) $(CLEAN_FILES)

fclean: clean
	$(RM) $(FCLEAN_FILES)

re: fclean all

show:
	@printf "%s\n \t%s\n" "SRC" "$(SRC)"
	@printf "%s\n \t%s\n" "OBJS" "$(OBJS)"
	@printf "%s\n \t%s\n" "DEPS" "$(DEPS)"
	@printf "%s\n \t%s\n" "CFLAGS" "$(CFLAGS)"
	@printf "%s\n \t%s\n" "LDFLAGS" "$(LDFLAGS)"
	@printf "%s\n \t%s\n" "LIBS" "$(LIBS)"
