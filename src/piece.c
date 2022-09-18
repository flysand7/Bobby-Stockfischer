
enum PieceColor {
    PIECE_BLACK,
    PIECE_WHITE,
} typedef PieceColor;

enum PieceKind {
    PIECE_P,
    PIECE_N,
    PIECE_B,
    PIECE_R,
    PIECE_Q,
    PIECE_K,
} typedef PieceKind;

static char piece_char_from_kind(PieceKind piece) {
    switch(piece) {
        case PIECE_N: return 'N';
        case PIECE_B: return 'B';
        case PIECE_R: return 'R';
        case PIECE_Q: return 'Q';
        case PIECE_K: return 'K';
        default:      return 0;
    }
}

static PieceKind piece_kind_from_char(char pn) {
    switch(pn) {
        case 'N': return PIECE_N;
        case 'B': return PIECE_B;
        case 'R': return PIECE_R;
        case 'Q': return PIECE_Q;
        case 'K': return PIECE_K;
        default:  return 0;
    }
}
