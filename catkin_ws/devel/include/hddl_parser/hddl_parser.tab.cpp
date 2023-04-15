// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "hddl_parser.tab.hpp"


// Unqualified %code blocks.
#line 29 "hddl_parser/src/hddl_parser.yacc"

    #include <fstream>
    #include <sstream>
    #include "hddl_parser.h"

    Predicate temp_predicate;
    std::vector<Predicate> temp_pred_vector;
    Params temp_params;
    Method temp_meth;
    Action temp_action;
    std::vector<std::string> temp_args;
    std::vector<std::string> temp_instances;
    int count = 0;

#line 60 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 151 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (HDDLParser& hddl_parser_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      hddl_parser (hddl_parser_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 3: // " number "
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 4: // " generic string "
      case 5: // " domain "
      case 6: // " define "
      case 7: // " problem "
      case 8: // " requirements "
      case 9: // " typing, htn, htn-method-prec "
      case 10: // " types "
      case 11: // " predicates "
      case 12: // " parameters "
      case 13: // " precondition "
      case 14: // " duration "
      case 15: // " effect "
      case 16: // " decrease "
      case 17: // " task "
      case 18: // " ordered-subtasks "
      case 19: // " subtasks "
      case 20: // " method "
      case 21: // " action "
      case 22: // " ( "
      case 23: // " : "
      case 24: // " ) "
      case 25: // " ? "
      case 26: // " - "
      case 27: // " = "
      case 28: // " and "
      case 29: // " not "
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 3: // " number "
        value.move< int > (YY_MOVE (that.value));
        break;

      case 4: // " generic string "
      case 5: // " domain "
      case 6: // " define "
      case 7: // " problem "
      case 8: // " requirements "
      case 9: // " typing, htn, htn-method-prec "
      case 10: // " types "
      case 11: // " predicates "
      case 12: // " parameters "
      case 13: // " precondition "
      case 14: // " duration "
      case 15: // " effect "
      case 16: // " decrease "
      case 17: // " task "
      case 18: // " ordered-subtasks "
      case 19: // " subtasks "
      case 20: // " method "
      case 21: // " action "
      case 22: // " ( "
      case 23: // " : "
      case 24: // " ) "
      case 25: // " ? "
      case 26: // " - "
      case 27: // " = "
      case 28: // " and "
      case 29: // " not "
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 3: // " number "
        value.copy< int > (that.value);
        break;

      case 4: // " generic string "
      case 5: // " domain "
      case 6: // " define "
      case 7: // " problem "
      case 8: // " requirements "
      case 9: // " typing, htn, htn-method-prec "
      case 10: // " types "
      case 11: // " predicates "
      case 12: // " parameters "
      case 13: // " precondition "
      case 14: // " duration "
      case 15: // " effect "
      case 16: // " decrease "
      case 17: // " task "
      case 18: // " ordered-subtasks "
      case 19: // " subtasks "
      case 20: // " method "
      case 21: // " action "
      case 22: // " ( "
      case 23: // " : "
      case 24: // " ) "
      case 25: // " ? "
      case 26: // " - "
      case 27: // " = "
      case 28: // " and "
      case 29: // " not "
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 3: // " number "
        value.move< int > (that.value);
        break;

      case 4: // " generic string "
      case 5: // " domain "
      case 6: // " define "
      case 7: // " problem "
      case 8: // " requirements "
      case 9: // " typing, htn, htn-method-prec "
      case 10: // " types "
      case 11: // " predicates "
      case 12: // " parameters "
      case 13: // " precondition "
      case 14: // " duration "
      case 15: // " effect "
      case 16: // " decrease "
      case 17: // " task "
      case 18: // " ordered-subtasks "
      case 19: // " subtasks "
      case 20: // " method "
      case 21: // " action "
      case 22: // " ( "
      case 23: // " : "
      case 24: // " ) "
      case 25: // " ? "
      case 26: // " - "
      case 27: // " = "
      case 28: // " and "
      case 29: // " not "
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (hddl_parser));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 3: // " number "
        yylhs.value.emplace< int > ();
        break;

      case 4: // " generic string "
      case 5: // " domain "
      case 6: // " define "
      case 7: // " problem "
      case 8: // " requirements "
      case 9: // " typing, htn, htn-method-prec "
      case 10: // " types "
      case 11: // " predicates "
      case 12: // " parameters "
      case 13: // " precondition "
      case 14: // " duration "
      case 15: // " effect "
      case 16: // " decrease "
      case 17: // " task "
      case 18: // " ordered-subtasks "
      case 19: // " subtasks "
      case 20: // " method "
      case 21: // " action "
      case 22: // " ( "
      case 23: // " : "
      case 24: // " ) "
      case 25: // " ? "
      case 26: // " - "
      case 27: // " = "
      case 28: // " and "
      case 29: // " not "
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 94 "hddl_parser/src/hddl_parser.yacc"
                                              { hddl_parser.domain_.domain_name_ = yystack_[1].value.as < std::string > (); }
#line 743 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"
    break;

  case 7:
#line 127 "hddl_parser/src/hddl_parser.yacc"
                         { hddl_parser.domain_.domain_requirements_.push_back(yystack_[0].value.as < std::string > ()); }
#line 749 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"
    break;

  case 10:
#line 136 "hddl_parser/src/hddl_parser.yacc"
    {
        while (temp_instances.size() > 0) {
            hddl_parser.domain_.domain_types_[temp_instances.back()] = yystack_[0].value.as < std::string > ();
            temp_instances.pop_back();
        }
    }
#line 760 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"
    break;

  case 12:
#line 145 "hddl_parser/src/hddl_parser.yacc"
                       { temp_instances.push_back(yystack_[0].value.as < std::string > ());}
#line 766 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"
    break;

  case 15:
#line 153 "hddl_parser/src/hddl_parser.yacc"
                                              {
        temp_predicate.name = yystack_[2].value.as < std::string > ();
        temp_predicate.pred_params = temp_params;
        hddl_parser.domain_.domain_predicates_.push_back(temp_predicate);

        /* reset */
        temp_params.params.clear();
        temp_params.params_map.clear();
        count = 0;
    }
#line 781 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"
    break;

  case 18:
#line 170 "hddl_parser/src/hddl_parser.yacc"
                                     {
        for(int i=0; i < count; i++) {
            temp_params.params_map[temp_args.at(i)] = yystack_[0].value.as < std::string > ();
        }

        temp_args.clear();
        count = 0;
    }
#line 794 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"
    break;

  case 20:
#line 181 "hddl_parser/src/hddl_parser.yacc"
                     {
        count++;
        temp_args.push_back(yystack_[0].value.as < std::string > ());
        temp_params.params.push_back(yystack_[0].value.as < std::string > ());
    }
#line 804 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"
    break;

  case 23:
#line 193 "hddl_parser/src/hddl_parser.yacc"
                                                        {
        Task temp_task;
        temp_task.name = yystack_[2].value.as < std::string > ();
        temp_task.task_params = temp_params;
        hddl_parser.domain_.domain_tasks_.push_back(temp_task);

        /* reset params */
        temp_params.params.clear();
        temp_params.params_map.clear();
        count = 0;
    }
#line 820 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"
    break;

  case 26:
#line 216 "hddl_parser/src/hddl_parser.yacc"
                                                                             {
        temp_meth.name = yystack_[4].value.as < std::string > ();
        temp_meth.meth_params = temp_params;
        hddl_parser.domain_.domain_meths_.push_back(temp_meth);

        temp_meth.subtasks.clear();

        /* reset */
        temp_params.params.clear();
        temp_params.params_map.clear();
        count = 0;
    }
#line 837 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"
    break;

  case 27:
#line 231 "hddl_parser/src/hddl_parser.yacc"
                                                               {
        /* parameters */
        temp_meth.task.name = yystack_[2].value.as < std::string > ();
        temp_meth.task.task_params.params = temp_args;
        temp_args.clear();
    }
#line 848 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"
    break;

  case 29:
#line 239 "hddl_parser/src/hddl_parser.yacc"
                              {
        temp_args.push_back(yystack_[0].value.as < std::string > ());
    }
#line 856 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"
    break;

  case 33:
#line 254 "hddl_parser/src/hddl_parser.yacc"
                          { temp_meth.ordered_subtasks = true; }
#line 862 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"
    break;

  case 34:
#line 254 "hddl_parser/src/hddl_parser.yacc"
                                                                                     { temp_meth.ordered_subtasks = false; }
#line 868 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"
    break;

  case 37:
#line 260 "hddl_parser/src/hddl_parser.yacc"
                                       {
        Task t;
        t.name = yystack_[2].value.as < std::string > ();
        t.task_params.params = temp_args;
        temp_meth.subtasks.push_back(t);

        temp_args.clear();
    }
#line 881 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"
    break;

  case 40:
#line 275 "hddl_parser/src/hddl_parser.yacc"
                                                   {temp_action.action_params = temp_params;}
#line 887 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"
    break;

  case 41:
#line 275 "hddl_parser/src/hddl_parser.yacc"
                                                                                                                           {
        temp_action.name = yystack_[5].value.as < std::string > ();

        hddl_parser.domain_.domain_actions_.push_back(temp_action);

        temp_action.effects.clear();
        temp_action.preconditions.clear();

        /* reset params */
        temp_params.params.clear();
        temp_params.params_map.clear();
        count = 0;
    }
#line 905 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"
    break;

  case 43:
#line 294 "hddl_parser/src/hddl_parser.yacc"
                                                                                    {
        temp_action.preconditions = temp_pred_vector;
        temp_pred_vector.clear();
    }
#line 914 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"
    break;

  case 45:
#line 304 "hddl_parser/src/hddl_parser.yacc"
                                                                                  {
        temp_action.effects = temp_pred_vector;
        temp_pred_vector.clear();
    }
#line 923 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"
    break;

  case 52:
#line 319 "hddl_parser/src/hddl_parser.yacc"
                              {
        temp_predicate.negated = false;

        temp_predicate.name = yystack_[2].value.as < std::string > ();
        temp_predicate.pred_params.params = temp_args;

        temp_pred_vector.push_back(temp_predicate);

        temp_args.clear();
    }
#line 938 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"
    break;

  case 53:
#line 331 "hddl_parser/src/hddl_parser.yacc"
                                                {
        temp_predicate.negated = true;

        temp_predicate.name = yystack_[3].value.as < std::string > ();
        temp_predicate.pred_params.params = temp_args;

        temp_pred_vector.push_back(temp_predicate);

        temp_args.clear();
    }
#line 953 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"
    break;


#line 957 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -110;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      21,    42,    49,    28,  -110,    16,    47,    29,  -110,    30,
      31,    33,    48,    34,    36,  -110,    50,    38,    37,     8,
    -110,    51,    40,    43,  -110,    55,  -110,  -110,    44,  -110,
      52,    53,  -110,    45,  -110,  -110,  -110,    -3,   -15,    62,
      -9,    54,  -110,   -10,  -110,  -110,    66,    67,  -110,    56,
      68,    13,    57,  -110,  -110,  -110,  -110,    61,    58,    56,
      70,    60,    59,    63,  -110,    64,    56,  -110,    10,  -110,
      69,    65,  -110,    71,    74,    72,    73,    19,    75,    77,
    -110,  -110,  -110,    80,  -110,  -110,    76,  -110,    78,    79,
    -110,     1,  -110,  -110,    81,    82,    83,    15,  -110,  -110,
      -4,  -110,  -110,  -110,  -110,    84,  -110,  -110,    85,    17,
      -6,  -110,  -110,    86,    87,    -2,  -110,  -110,  -110,    88,
    -110,  -110,    20,    -1,    -5,  -110,    89,  -110,  -110,  -110,
    -110,  -110,    22,    90,  -110
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     1,     0,     0,     0,     2,     0,
       0,     0,     0,     0,     0,     5,     0,     0,     0,     0,
       9,     0,     0,     0,    21,     0,     4,     6,    11,    14,
       0,     0,    22,     0,    24,     7,     8,     0,     0,     0,
       0,     0,    25,     0,    38,    12,     0,     0,    13,     0,
       0,     0,     0,     3,    39,    10,    17,     0,     0,     0,
       0,     0,    19,     0,    23,     0,     0,    15,     0,    17,
       0,     0,    40,     0,     0,    19,     0,     0,     0,     0,
      20,    18,    16,     0,    33,    34,     0,    26,     0,     0,
      28,     0,    30,    32,     0,     0,     0,     0,    28,    35,
       0,    43,    47,    50,    51,     0,    41,    27,     0,     0,
       0,    19,    42,     0,     0,     0,    45,    29,    37,     0,
      31,    36,     0,     0,     0,    48,     0,    44,    52,    46,
      49,    19,     0,     0,    53
  };

  const signed char
  parser::yypgoto_[] =
  {
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,   -53,    25,  -101,  -110,    92,  -110,    91,  -110,    -8,
    -110,  -110,  -110,  -110,     0,  -110,    93,  -110,  -110,  -110,
       6,  -110,  -109,  -110,  -110
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     9,    11,    19,    27,    14,    28,    37,    18,
      38,    58,    62,    68,    23,    24,    33,    34,    71,    97,
      78,    92,    86,   110,    93,    43,    44,    79,    89,    96,
     101,   124,   102,   103,   104
  };

  const unsigned char
  parser::yytable_[] =
  {
     111,    45,   111,   111,   125,    98,    65,    47,    39,    48,
     122,    50,    52,    72,    53,   130,   119,   123,   120,   129,
     112,     6,   127,    46,   113,   114,   113,   114,   114,    99,
     132,    25,    26,    50,    60,    73,    74,    84,    85,   107,
     108,   118,   108,     1,   128,    73,   133,    73,     3,     4,
       5,     7,    10,     8,    12,    13,    15,    16,    17,    22,
      20,    21,    29,    30,    35,    31,    49,    41,    36,    39,
      55,    56,    59,    63,    66,    80,    40,    51,    81,    57,
      61,    60,    64,    67,    90,    69,    76,    70,    77,   117,
     109,    94,    98,   131,    75,    83,    82,   105,    91,    87,
      88,     0,    95,   100,     0,     0,   115,   106,   123,   126,
     121,   116,     0,     0,   134,    32,     0,     0,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54
  };

  const short
  parser::yycheck_[] =
  {
       4,     4,     4,     4,   113,     4,    59,    22,    17,    24,
     111,    20,    22,    66,    24,   124,    22,    22,    24,    24,
      24,     5,    24,    26,    28,    29,    28,    29,    29,    28,
     131,    23,    24,    20,    21,    25,    26,    18,    19,    24,
      25,    24,    25,    22,    24,    25,    24,    25,     6,     0,
      22,     4,    22,    24,    23,    22,     8,    23,    22,    22,
      10,    23,    11,    23,     9,    22,     4,    22,    24,    17,
       4,     4,     4,    12,     4,     4,    23,    23,     4,    23,
      23,    21,    24,    24,     4,    22,    17,    23,    23,     4,
      98,    13,     4,     4,    69,    22,    24,    15,    22,    24,
      23,    -1,    23,    22,    -1,    -1,    22,    24,    22,    22,
     110,   105,    -1,    -1,    24,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43
  };

  const signed char
  parser::yystos_[] =
  {
       0,    22,    32,     6,     0,    22,     5,     4,    24,    33,
      22,    34,    23,    22,    37,     8,    23,    22,    40,    35,
      10,    23,    22,    45,    46,    23,    24,    36,    38,    11,
      23,    22,    46,    47,    48,     9,    24,    39,    41,    17,
      23,    22,    48,    56,    57,     4,    26,    22,    24,     4,
      20,    23,    22,    24,    57,     4,     4,    23,    42,     4,
      21,    23,    43,    12,    24,    42,     4,    24,    44,    22,
      23,    49,    42,    25,    26,    43,    17,    23,    51,    58,
       4,     4,    24,    22,    18,    19,    53,    24,    23,    59,
       4,    22,    52,    55,    13,    23,    60,    50,     4,    28,
      22,    61,    63,    64,    65,    15,    24,    24,    25,    50,
      54,     4,    24,    28,    29,    22,    61,     4,    24,    22,
      24,    55,    44,    22,    62,    63,    22,    24,    24,    24,
      63,     4,    44,    24,    24
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    31,    33,    32,    34,    35,    35,    36,    37,    38,
      38,    39,    39,    40,    41,    41,    42,    43,    43,    44,
      44,    45,    45,    46,    47,    47,    48,    49,    50,    50,
      51,    52,    52,    53,    53,    54,    54,    55,    56,    56,
      58,    57,    59,    59,    60,    60,    61,    61,    62,    62,
      63,    63,    64,    65
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,    14,     5,     0,     2,     2,     5,     0,
       4,     0,     2,     5,     0,     5,     5,     0,     4,     0,
       3,     1,     2,     6,     1,     2,     8,     6,     0,     3,
       3,     4,     1,     1,     1,     0,     2,     4,     1,     2,
       0,     9,     4,     3,     4,     3,     4,     1,     1,     2,
       1,     1,     4,     7
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\" end_of_file \"", "error", "$undefined", "\" number \"",
  "\" generic string \"", "\" domain \"", "\" define \"", "\" problem \"",
  "\" requirements \"", "\" typing, htn, htn-method-prec \"",
  "\" types \"", "\" predicates \"", "\" parameters \"",
  "\" precondition \"", "\" duration \"", "\" effect \"", "\" decrease \"",
  "\" task \"", "\" ordered-subtasks \"", "\" subtasks \"", "\" method \"",
  "\" action \"", "\" ( \"", "\" : \"", "\" ) \"", "\" ? \"", "\" - \"",
  "\" = \"", "\" and \"", "\" not \"", "\"invalid character\"", "$accept",
  "hddl_main_structure", "$@1", "requirements", "reqs", "req", "types",
  "types_content", "instances", "predicates", "hpreds", "params",
  "only_params", "keys", "tasks", "task", "methods", "method", "meth_task",
  "simple_params", "subtasks", "meth_sub", "ordered", "subts", "subt",
  "actions", "action", "$@2", "preconditions", "effects", "pred_body",
  "preds", "pred", "positive_pred", "negative_pred", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    94,    94,    94,   119,   122,   123,   127,   131,   134,
     135,   144,   145,   149,   152,   153,   166,   169,   170,   180,
     181,   189,   189,   193,   206,   206,   216,   231,   238,   239,
     247,   251,   251,   254,   254,   256,   257,   260,   270,   270,
     275,   275,   294,   294,   304,   304,   310,   310,   313,   313,
     316,   316,   319,   331
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1433 "/home/thomas/Documents/university/ar/catkin_ws/devel/include/hddl_parser/hddl_parser.tab.cpp"

#line 342 "hddl_parser/src/hddl_parser.yacc"


/* =============================

   Grammar definition ends here

================================*/

void yy::parser::error(const location_type& error_location, const std::string& m)
{
    // show error to the user: 1. type of error , 2. filename , 3. error location (line and column)
    std::cerr << "\n\033[1;31merror: \033[0m" << m << "\nwhile parsing file: " << *error_location.begin.filename << \
    " line : " << error_location.begin.line << ", column : " << error_location.begin.column \
    << ":" << error_location.end.column << "\n" << std::endl;

    // print the file to console and mark where the error is with a "^"
    std::ifstream file(error_location.begin.filename->c_str());
    if (file.is_open())
    {
        std::string line;
        int line_number = 0;
        std::cout << "========  " << *error_location.begin.filename << "  ========" << std::endl;
        // print all lines one by one
        while(std::getline(file, line))
        {
            // print "^" chars to mark where the error is located
            if(error_location.begin.line == line_number++)
            {
                std::stringstream ss_marker;
                // add spaces to string stream marker until error column starts
                for(size_t i = 1; i < error_location.begin.column; i++)
                    ss_marker << " ";

                // add ^ chars from the beginning of the column till end of error
                for(size_t j = error_location.begin.column; j < (error_location.end.column); j++)
                    ss_marker << "^";

                // print line that shows where the error is found
                // std::cout << ss_marker.str() << std::endl;
                std::cout << "\033[1;32m" << ss_marker.str() << "\033[0m" << std::endl;
            }

            // print next line
            std::istringstream ss(line);
            std::cout << ss.str() << std::endl;
        }
        std::cout << "=======================================" << std::endl;
    }
}
