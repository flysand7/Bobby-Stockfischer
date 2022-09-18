
enum {
    MOVE_NORMAL,
    MOVE_CASTLE_S,
    MOVE_CASTLE_L,
} typedef MoveKind;

enum {
    MOVE_CAPTURE = 0x01,
    MOVE_CHECK   = 0x02,
    MOVE_MATE    = 0x04,
    // MOVE_EP      = 0x08, ?
} typedef MoveFlags;

struct MoveInfo typedef MoveInfo;
struct MoveInfo {
    MoveKind  kind;
    MoveFlags flags;
    PieceKind subject;
    int       from_file;
    int       from_rank;
    int       to_file;
    int       to_rank;
};


#define IS_FILE(ch) ('a' <= (ch) && (ch) <= 'f')
#define IS_RANK(ch) ('1' <= (ch) && (ch) <= '8')
#define TO_FILE(ch) ((ch) - 'a')
#define TO_RANK(ch) ((ch) - '1')
#define FROM_FILE(ch) ((ch) + 'a')
#define FROM_RANK(ch) ((ch) + '1')

static size_t parse_an(MoveInfo *move, char const *an) {
    char const *an_start = an;
    *move = (MoveInfo) {0};
    if(strcmp(an, "O-O") == 0) {
        move->kind = MOVE_CASTLE_S;
        move->subject = PIECE_K;
        an += 3;
    }
    else if(strcmp(an, "O-O-O") == 0) {
        move->kind = MOVE_CASTLE_L;
        move->subject = PIECE_K;
        an += 5;
    }
    else {
        move->kind = MOVE_NORMAL;
        move->subject = piece_kind_from_char(*an);
        if(move->subject != PIECE_P) {
            an += 1;
        }
        int file_1 = -1;
        int rank_1 = -1;
        int file_2 = -1;
        int rank_2 = -1;
        if(IS_FILE(*an)) {
            file_1 = TO_FILE(*an);
            ++an;
        }
        if(IS_RANK(*an)) {
            rank_1 = TO_RANK(*an);
            ++an;
        }
        if(*an == 'x') {
            move->flags |= MOVE_CAPTURE;
            ++an;
        }
        if(IS_FILE(*an)) {
            file_2 = TO_FILE(*an);
            ++an;
        }
        if(IS_RANK(*an)) {
            rank_2 = TO_RANK(*an);
            ++an;
        }
        if(file_2 == -1 && rank_2 == -1) {
            if(move->flags & MOVE_CAPTURE) {
                // target square not specified (Rc8x)
                return 0;
            }
            file_2 = file_1;
            rank_2 = rank_1;
            file_1 = -1;
            rank_1 = -1;
        }
        if(file_2 == -1 || rank_2 == -1) {
            return 0; // insufficient information (Rcxb)
        }
        move->from_file = file_1;
        move->from_rank = rank_1;
        move->to_file   = file_2;
        move->to_rank   = rank_2;
    }
    if(*an == '+') {
        move->flags |= MOVE_CHECK;
        ++an;
    }
    else if(*an == '#') {
        move->flags |= MOVE_CHECK;
        move->flags |= MOVE_MATE;
        ++an;
    }
    return (size_t)(an - an_start);
}

static int write_an(MoveInfo *move, char *an) {
    if(move->kind == MOVE_CASTLE_S) {
        strcpy(an, "O-O");
        an += 3;
    }
    else if(move->kind == MOVE_CASTLE_L) {
        strcpy(an, "O-O-O");
        an += 5;
    }
    else if(move->kind == MOVE_NORMAL) {
        if(move->subject != PIECE_P) {
            *an++ = piece_char_from_kind(move->subject);
        }
        if(move->from_file != -1) {
            *an++ = FROM_FILE(move->from_file);
        }
        if(move->from_rank != -1) {
            *an++ = FROM_RANK(move->from_rank);
        }
        if(move->flags & MOVE_CAPTURE) {
            *an++ = 'x';
        }
        *an++ = FROM_FILE(move->to_file);
        *an++ = FROM_RANK(move->to_rank);
    }
    if(move->flags & MOVE_MATE) {
        *an++ = '#';
    }
    else if(move->flags & MOVE_CHECK) {
        *an++ = '+';
    }
    return 1;
}

#undef IS_FILE
#undef IS_RANK
#undef TO_RANK
#undef TO_FILE
#undef FROM_RANK
#undef FROM_FILE

