"""
LeetCode Solutions PDF Generator
Combines all C++ solutions into a single PDF document with:
- Table of contents with clickable hyperlinks
- Solutions grouped by category
- Syntax highlighting for C++ code
- One solution per page
- Professional blue color scheme
"""

import re
from pathlib import Path
from reportlab.lib.pagesizes import letter
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.lib.units import inch
from reportlab.platypus import (
    SimpleDocTemplate, Paragraph, Spacer, PageBreak, Preformatted, XPreformatted
)
from reportlab.platypus.tableofcontents import TableOfContents
from reportlab.lib.colors import HexColor
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.ttfonts import TTFont

# Try to use a monospace font for code
try:
    pdfmetrics.registerFont(TTFont('Consolas', 'consola.ttf'))
    CODE_FONT = 'Consolas'
except:
    CODE_FONT = 'Courier'


# ==================== COLOR SCHEME (Professional Blues + Monokai Pro Machine) ====================
COLORS = {
    'primary':        HexColor('#1E3A5F'),    # Dark navy blue - titles
    'secondary':      HexColor('#2E5984'),    # Medium blue - category headers
    'accent':         HexColor('#3776AB'),    # Python blue - problem names
    'text':           HexColor('#2C3E50'),    # Dark gray-blue - body text
    'muted':          HexColor('#5D6D7E'),    # Muted blue-gray - filenames
    'light_bg':       HexColor('#273136'),    # Monokai Pro Machine background
    'border':         HexColor('#3A4449'),    # Monokai Pro Machine border
    # Syntax highlighting (Monokai Pro - Machine filter)
    'code_keyword':   HexColor('#FF6D7E'),    # Red/Pink - keywords
    'code_type':      HexColor('#A2E57B'),    # Green - types
    'code_string':    HexColor('#FFED72'),    # Yellow - strings
    'code_comment':   HexColor("#FFB700"),    # Orange - comments
    'code_number':    HexColor('#BAB0FF'),    # Purple - numbers
    'code_preproc':   HexColor('#FFB270'),    # Orange - preprocessor
    'code_default':   HexColor('#F2FFFC'),    # White - default text
    'code_cyan':      HexColor('#7CD5F1'),    # Cyan - for additional highlighting
}

# Categories in desired order
CATEGORIES = [
    "Arrays and Hashing",
    "Two Pointers",
    "Sliding Window",
    "Stack",
    "Binary Search",
    "Linked List",
    "Trees",
    "Tries",
    "Priority Queue",
    "Backtracking",
    "Graphs",
    "1-D DP",
    "2-D DP",
    "Greedy",
    "Intervals",
    "Math and Geometry",
    "Bit Manipulation",
    "Design",
    "Core Skills",
    "Brute Force"
]

# C++ keywords for syntax highlighting
CPP_KEYWORDS = {
    'auto', 'break', 'case', 'catch', 'class', 'const', 'continue', 'default',
    'delete', 'do', 'else', 'enum', 'explicit', 'export', 'extern', 'false',
    'for', 'friend', 'goto', 'if', 'inline', 'mutable', 'namespace', 'new',
    'nullptr', 'operator', 'private', 'protected', 'public', 'register',
    'return', 'sizeof', 'static', 'struct', 'switch', 'template', 'this',
    'throw', 'true', 'try', 'typedef', 'typeid', 'typename', 'union',
    'using', 'virtual', 'void', 'volatile', 'while', 'override', 'final',
    'NULL', 'include', 'define', 'ifdef', 'ifndef', 'endif', 'pragma'
}

CPP_TYPES = {
    'int', 'long', 'short', 'char', 'bool', 'float', 'double', 'unsigned',
    'signed', 'size_t', 'string', 'vector', 'map', 'unordered_map', 'set',
    'unordered_set', 'pair', 'queue', 'stack', 'deque', 'list', 'array',
    'priority_queue', 'bitset', 'tuple', 'stringstream', 'TreeNode', 'Node',
    'ListNode'
}


def get_problem_name(filename):
    """Convert filename to readable problem name."""
    name = filename.replace('.cpp', '').replace('_', ' ')
    return name.title()


def make_anchor_name(text):
    """Create a valid anchor name from text."""
    return re.sub(r'[^a-zA-Z0-9]', '_', text.lower())


def syntax_highlight_cpp(code):
    """Apply syntax highlighting to C++ code and return XML-formatted string."""
    
    def escape_xml(text):
        return text.replace('&', '&amp;').replace('<', '&lt;').replace('>', '&gt;')
    
    def colorize(text, color):
        return f'<font color="{color}">{escape_xml(text)}</font>'
    
    result = []
    i = 0
    
    while i < len(code):
        # Multi-line comments
        if code[i:i+2] == '/*':
            end = code.find('*/', i + 2)
            if end == -1:
                end = len(code)
            else:
                end += 2
            result.append(colorize(code[i:end], COLORS['code_comment'].hexval()))
            i = end
            continue
        
        # Single-line comments
        if code[i:i+2] == '//':
            end = code.find('\n', i)
            if end == -1:
                end = len(code)
            result.append(colorize(code[i:end], COLORS['code_comment'].hexval()))
            i = end
            continue
        
        # Preprocessor directives
        if code[i] == '#':
            end = code.find('\n', i)
            if end == -1:
                end = len(code)
            result.append(colorize(code[i:end], COLORS['code_preproc'].hexval()))
            i = end
            continue
        
        # Strings
        if code[i] in '"\'':
            quote = code[i]
            end = i + 1
            while end < len(code):
                if code[end] == '\\' and end + 1 < len(code):
                    end += 2
                elif code[end] == quote:
                    end += 1
                    break
                else:
                    end += 1
            result.append(colorize(code[i:end], COLORS['code_string'].hexval()))
            i = end
            continue
        
        # Numbers
        if code[i].isdigit() or (code[i] == '.' and i + 1 < len(code) and code[i+1].isdigit()):
            end = i
            while end < len(code) and (code[end].isalnum() or code[end] == '.'):
                end += 1
            result.append(colorize(code[i:end], COLORS['code_number'].hexval()))
            i = end
            continue
        
        # Identifiers and keywords
        if code[i].isalpha() or code[i] == '_':
            end = i
            while end < len(code) and (code[end].isalnum() or code[end] == '_'):
                end += 1
            word = code[i:end]
            if word in CPP_KEYWORDS:
                result.append(colorize(word, COLORS['code_keyword'].hexval()))
            elif word in CPP_TYPES:
                result.append(colorize(word, COLORS['code_type'].hexval()))
            else:
                result.append(escape_xml(word))
            i = end
            continue
        
        # Default: single character
        result.append(escape_xml(code[i]))
        i += 1
    
    return ''.join(result)


def collect_solutions(repo_path):
    """Collect all solutions grouped by category."""
    solutions = {}
    
    for category in CATEGORIES:
        category_path = repo_path / category
        if category_path.exists() and category_path.is_dir():
            files = list(category_path.glob('*.cpp'))
            if files:
                solutions[category] = []
                for f in sorted(files):
                    with open(f, 'r', encoding='utf-8') as file:
                        code = file.read()
                    solutions[category].append({
                        'filename': f.name,
                        'problem_name': get_problem_name(f.name),
                        'code': code
                    })
    
    return solutions


class MyDocTemplate(SimpleDocTemplate):
    """Custom doc template that notifies TOC of headings."""
    
    def afterFlowable(self, flowable):
        """Register TOC entries after each flowable."""
        if hasattr(flowable, 'toc_level'):
            level = flowable.toc_level
            text = flowable.getPlainText()
            link = getattr(flowable, 'toc_link', None)
            self.notify('TOCEntry', (level, text, self.page, link))


class LinkedHeading(Paragraph):
    """A paragraph that acts as a bookmark destination."""
    
    def __init__(self, text, style, anchor_name, toc_level=None):
        self.anchor_name = anchor_name
        if toc_level is not None:
            self.toc_level = toc_level
            self.toc_link = anchor_name
        Paragraph.__init__(self, f'<a name="{anchor_name}"/>{text}', style)


def create_pdf(repo_path, output_filename="LeetCode_Solutions.pdf"):
    """Generate the PDF document."""
    
    repo_path = Path(repo_path)
    output_path = repo_path / output_filename
    
    # Collect all solutions
    print("Collecting solutions...")
    solutions = collect_solutions(repo_path)
    
    if not solutions:
        print("No solutions found!")
        return
    
    total_problems = sum(len(probs) for probs in solutions.values())
    print(f"Found {total_problems} solutions in {len(solutions)} categories")
    
    # Create document
    doc = MyDocTemplate(
        str(output_path),
        pagesize=letter,
        rightMargin=0.75*inch,
        leftMargin=0.75*inch,
        topMargin=0.75*inch,
        bottomMargin=0.75*inch
    )
    
    # Define styles
    styles = getSampleStyleSheet()
    
    title_style = ParagraphStyle(
        'CustomTitle',
        parent=styles['Heading1'],
        fontSize=32,
        spaceAfter=20,
        alignment=1,
        textColor=COLORS['primary'],
        fontName='Helvetica-Bold'
    )
    
    subtitle_style = ParagraphStyle(
        'Subtitle',
        parent=styles['Normal'],
        fontSize=14,
        spaceAfter=40,
        alignment=1,
        textColor=COLORS['secondary']
    )
    
    stats_style = ParagraphStyle(
        'Stats',
        parent=styles['Normal'],
        fontSize=12,
        spaceAfter=20,
        alignment=1,
        textColor=COLORS['accent'],
        fontName='Helvetica-Bold'
    )
    
    category_style = ParagraphStyle(
        'Category',
        parent=styles['Heading1'],
        fontSize=22,
        spaceBefore=20,
        spaceAfter=15,
        textColor=COLORS['secondary'],
        fontName='Helvetica-Bold'
    )
    
    problem_style = ParagraphStyle(
        'Problem',
        parent=styles['Heading2'],
        fontSize=16,
        spaceBefore=10,
        spaceAfter=5,
        textColor=COLORS['accent'],
        fontName='Helvetica-Bold'
    )
    
    filename_style = ParagraphStyle(
        'Filename',
        parent=styles['Normal'],
        fontSize=10,
        spaceAfter=15,
        textColor=COLORS['muted'],
        fontName='Courier'
    )
    
    code_style = ParagraphStyle(
        'Code',
        parent=styles['Code'],
        fontSize=8,
        fontName=CODE_FONT,
        leading=11,
        textColor=COLORS['code_default'],
        backColor=COLORS['light_bg'],
        borderPadding=(10, 10, 10, 10),
        borderColor=COLORS['border'],
        borderWidth=1,
    )
    
    toc_heading_style = ParagraphStyle(
        'TOCHeading',
        parent=styles['Heading1'],
        fontSize=24,
        spaceAfter=30,
        alignment=1,
        textColor=COLORS['primary'],
        fontName='Helvetica-Bold'
    )
    
    # Build story (content)
    story = []
    
    # Title page
    story.append(Spacer(1, 1.5*inch))
    story.append(Paragraph("LeetCode Solutions", title_style))
    story.append(Spacer(1, 0.2*inch))
    story.append(Paragraph("A collection of algorithm solutions in C++", subtitle_style))
    story.append(Spacer(1, 0.3*inch))
    
    # Stats
    stats_text = f"📊 {total_problems} Problems  •  📁 {len(solutions)} Categories"
    story.append(Paragraph(stats_text, stats_style))
    story.append(PageBreak())
    
    # Table of Contents
    story.append(Paragraph("Table of Contents", toc_heading_style))
    story.append(Spacer(1, 0.3*inch))
    
    toc = TableOfContents()
    toc.levelStyles = [
        ParagraphStyle(
            'TOCLevel0',
            fontName='Helvetica-Bold',
            fontSize=13,
            leftIndent=20,
            spaceBefore=12,
            leading=18,
            textColor=COLORS['secondary']
        ),
        ParagraphStyle(
            'TOCLevel1', 
            fontName='Helvetica',
            fontSize=11,
            leftIndent=45,
            spaceBefore=6,
            leading=15,
            textColor=COLORS['accent']
        ),
    ]
    toc.dotsMinLevel = 0  # Add dots to all levels
    story.append(toc)
    story.append(PageBreak())
    
    # Solutions by category
    for category, problems in solutions.items():
        # Category header (TOC level 0)
        cat_anchor = make_anchor_name(category)
        cat_heading = LinkedHeading(
            f"📁 {category}", 
            category_style, 
            cat_anchor, 
            toc_level=0
        )
        story.append(cat_heading)
        story.append(Spacer(1, 0.2*inch))
        
        for i, problem in enumerate(problems):
            # Problem header (TOC level 1) with anchor
            prob_anchor = make_anchor_name(f"{category}_{problem['problem_name']}")
            prob_heading = LinkedHeading(
                problem['problem_name'],
                problem_style,
                prob_anchor,
                toc_level=1
            )
            story.append(prob_heading)
            
            # Filename
            story.append(Paragraph(f"📄 {problem['filename']}", filename_style))
            
            # Syntax highlighted code
            highlighted_code = syntax_highlight_cpp(problem['code'])
            highlighted_code = highlighted_code.replace('\t', '    ')
            story.append(XPreformatted(highlighted_code, code_style))
            
            # Page break after each solution
            story.append(PageBreak())
    
    # Build PDF (multiBuild needed for TOC)
    print("Generating PDF...")
    doc.multiBuild(story)
    
    print(f"✅ PDF created successfully: {output_path}")
    return output_path


if __name__ == "__main__":
    # Automatically use the directory where this script is located
    REPO_PATH = Path(__file__).parent.resolve()
    
    print(f"Generating PDF from: {REPO_PATH}")
    create_pdf(REPO_PATH)
