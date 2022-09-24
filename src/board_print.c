
static void print_bb(bb_t bb) {
    printf("   +----------------+\n");
    for(int rank = 8; rank-- != 0;) {
        printf("%02d |", rank+1);
        for(int file = 0; file != 8; ++file) {
            int i = rank*8 + file;
            bb_t x = UINT64_C(1) << i;
            if(x & bb) {
                printf(". ");
            }
            else {
                printf("  ");
            }
        }
        printf("|\n");
    }
    printf("   +----------------+\n");
    printf("    A B C D E F G H\n");
}

static void print_board(Board *board) {
    printf("   +----------------+\n");
    for(int rank = 8; rank-- != 0;) {
        printf("%02d |", rank+1);
        for(int file = 0; file != 8; ++file) {
            int color;
            int piece;
            piece = board_piece_at(board, file, rank, &color);
            if(piece != -1) {
                if(color == COLOR_BLACK) {
                    printf("%c ", piece_char_from_kind_lower(piece));
                }
                else {
                    printf("%c ", piece_char_from_kind(piece));
                }
            }
            else {
                printf("  ");
            }
        }
        printf("|\n");
    }
    printf("   +----------------+\n");
    printf("    A B C D E F G H\n");
}

static int print_moves(Board *board, int file, int rank) {
    bb_t piece_loc = UINT64_C(1) << (rank*8 + file);
    int color;
    int piece = board_piece_at(board, file, rank, &color);
    if(piece == -1) {
        return 0;
    }
    bb_t moves = board_valid_moves(board, piece_loc, piece, color);
    printf("   +----------------+\n");
    for(int rank = 8; rank-- != 0;) {
        printf("%02d |", rank+1);
        for(int file = 0; file != 8; ++file) {
            int i = rank*8 + file;
            bb_t cell = UINT64_C(1) << i;
            if(cell & moves) {
                if(cell & board_pieces(board, COLOR_BLACK)) {
                    printf("x ");
                }
                else {
                    printf(". ");
                }
            }
            else if(cell & piece_loc) {
                if(color == COLOR_BLACK) {
                    printf("%c ", piece_char_from_kind_lower(piece));
                }
                else {
                    printf("%c ", piece_char_from_kind(piece));
                }
            }
            else {
                int color;
                int piece;
                piece = board_piece_at(board, file, rank, &color);
                if(piece != -1) {
                    if(color == COLOR_BLACK) {
                        printf("%c ", piece_char_from_kind_lower(piece));
                    }
                    else {
                        printf("%c ", piece_char_from_kind(piece));
                    }
                }
                else {
                    printf("  ");
                }
            }
        }
        printf("|\n");
    }
    printf("   +----------------+\n");
    printf("    A B C D E F G H\n");
    return 1;
}
