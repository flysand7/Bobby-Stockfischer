
static int board_load_fen(Board *board, char const *fen) {
    board_empty(board);
    for(int rank = 8; rank-- != 0;) {
        int file = 0;
        do {
            if(islower(*fen)) {
                PieceKind piece = piece_kind_from_char_lower(*fen);
                PieceColor color = COLOR_BLACK;
                board_put_at(board, file, rank, piece, color);
                ++fen;
                ++file;
            }
            else if(isupper(*fen)) {
                PieceKind piece = piece_kind_from_char(*fen);
                PieceColor color = COLOR_WHITE;
                board_put_at(board, file, rank, piece, color);
                ++fen;
                ++file;
            }
            else if(isdigit(*fen)) {
                int files = *fen-'0';
                file += files;
                ++fen;
            }
            else {
                return 0;
            }
        } while(file != 8);
        if(rank != 0) {
            if(*fen != '/') return 0;
            ++fen;
        }
    }
    if(*fen != ' ') {
        return 0;
    }
    return 1;
}
